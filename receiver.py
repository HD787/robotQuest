import socket
import struct
import time
from collections import defaultdict
import os

class ImageReceiver:
    def __init__(self, host='127.0.0.1', port=8081):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.bind((host, port))
        self.buffer_size = 65535  # Max UDP packet size
        self.header_size = 8  # Size of PacketHeader struct in C++
        
        # Create output directory if it doesn't exist
        self.output_dir = 'data/received_images'
        os.makedirs(self.output_dir, exist_ok=True)
        
        print(f'Listening on {host}:{port}...')

    def parse_header(self, data):
        """Parse the packet header containing total_chunks and chunk_index."""
        return struct.unpack('II', data[:self.header_size])  # Two uint32_t values

    def receive_image(self):
        """Receive and reconstruct a complete image from chunks."""
        chunks = defaultdict(dict)  # Dictionary to store chunks for each image
        current_image_chunks = None
        expected_chunks = None
        
        while True:
            try:
                data, addr = self.sock.recvfrom(self.buffer_size)
                
                # Parse header
                total_chunks, chunk_index = self.parse_header(data)
                chunk_data = data[self.header_size:]
                
                # If this is the first chunk of a new image
                if chunk_index == 0:
                    current_image_chunks = total_chunks
                    expected_chunks = set(range(total_chunks))
                    
                # Store the chunk
                chunks[total_chunks][chunk_index] = chunk_data
                
                # Check if we have all chunks for the current image
                if current_image_chunks and len(chunks[current_image_chunks]) == current_image_chunks:
                    # Reconstruct the image
                    image_data = bytearray()
                    for i in range(current_image_chunks):
                        image_data.extend(chunks[current_image_chunks][i])
                    
                    # Save the image
                    timestamp = int(time.time() * 1000)  # Use milliseconds for unique filename
                    filename = f'{self.output_dir}/image_{timestamp}.jpg'
                    with open(filename, 'wb') as f:
                        f.write(image_data)
                    
                    print(f'Saved complete image: {filename} ({len(image_data)} bytes)')
                    
                    # Clear the chunks for this image
                    del chunks[current_image_chunks]
                    current_image_chunks = None
                    
            except Exception as e:
                print(f'Error receiving data: {e}')
                continue

    def run(self):
        """Start the receiver."""
        try:
            print('Starting image receiver...')
            self.receive_image()
        except KeyboardInterrupt:
            print('\nShutting down receiver...')
        finally:
            self.sock.close()

if __name__ == '__main__':
    receiver = ImageReceiver()
    receiver.run()