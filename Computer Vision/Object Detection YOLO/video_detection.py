from ultralytics import YOLO
import cv2

model = YOLO("C:/Users/sthab/Documents/UCT Final Year/Project/Computer Vision/yolov8n.pt")

model.predict(source="C:/Users/sthab/Documents/UCT Final Year/Project/Computer Vision/Object Detection YOLO/test data/WhatsApp Image 2024-04-15 at 15.34.10_a7d16fc3.jpg",show=True,conf=0.5)
