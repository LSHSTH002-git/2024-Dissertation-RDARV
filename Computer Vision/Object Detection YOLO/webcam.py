import cv2
import socket
import pickle
import struct

# Create socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('192.168.68.68', 9999))
connection = client_socket.makefile('rb')

try:
    while True:
        # Read frame length from the server
        data = connection.read(struct.calcsize("<L"))
        if not data:
            break
        # Unpack frame length and deserialize frame
        frame_size = struct.unpack("<L", data)[0]
        frame_data = connection.read(frame_size)
        frame = pickle.loads(frame_data)
        # Display frame
        cv2.imshow('Video', frame)
        cv2.waitKey(1)
except KeyboardInterrupt:
    connection.close()
    client_socket.close()
    cv2.destroyAllWindows()
