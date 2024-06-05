import cv2
import socket
import pickle
import struct

# Load YOLOv8 model
# Already downloaded and set up the YOLOv8 model
yolo_model = cv2.dnn.readNet("yolov8.weights", "yolov8.cfg")

# Load coco.names file containing class names
with open("coco.names", "r") as f:
    classes = f.read().strip().split("\n")

# Create socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('RaspberryPi_IP_Address', 9999))
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
        
        # Perform object detection using YOLOv8
        blob = cv2.dnn.blobFromImage(frame, 1/255.0, (416, 416), swapRB=True, crop=False)
        yolo_model.setInput(blob)
        outputs = yolo_model.forward()

        # Loop over each of the detections
        for detection in outputs:
            # Extract confidence and class ID
            scores = detection[5:]
            class_id = np.argmax(scores)
            confidence = scores[class_id]

            # Filter out weak detections
            if confidence > 0.5:
                # Get bounding box coordinates
                box = detection[0:4] * np.array([W, H, W, H])
                (centerX, centerY, width, height) = box.astype("int")
                x = int(centerX - (width / 2))
                y = int(centerY - (height / 2))

                # Draw bounding box and label on the frame
                color = (0, 255, 0)  # Green color for bounding box
                cv2.rectangle(frame, (x, y), (x + width, y + height), color, 2)
                label = "{}: {:.2f}%".format(classes[class_id], confidence * 100)
                cv2.putText(frame, label, (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 2)

        # Display frame with bounding boxes
        cv2.imshow('Object Detection', frame)
        cv2.waitKey(1)
except KeyboardInterrupt:
    connection.close()
    client_socket.close()
    cv2.destroyAllWindows()
