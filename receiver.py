import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(('127.0.0.1', 8081))  # Listen on 8081 where C++ is sending to
print('Listening on port 8081...')

while True:
    data, addr = sock.recvfrom(65535)
    print(f'Received {len(data)} bytes from {addr}')