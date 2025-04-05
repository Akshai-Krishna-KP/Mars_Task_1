import cv2 as cv
import numpy as np
import math

#Camera Specification
HORIZONTAL_RESOLUTION = 1280 #px
VERTICAL_RESOLUTION = 720 # px
DIAGONAL_FOV = 55 # degree
REAL_ARROW_WIDTH = 17.0 # cm

def focal_length():
	diagonal_length = math.sqrt(HORIZONTAL_RESOLUTION ** 2 + VERTICAL_RESOLUTION ** 2)
	focal_len = (diagonal_length / 2) / (math.tan(DIAGONAL_FOV / 2))

def detect_arrow(image_path):
    #Read the image
	image = cv.imread(image_path)
	gray = cv.cvtColor(image, cv.COLOR_BGR2GRAY)
    
	#Apply the Gaussian Blue to reduce noise
	blurred = cv.GaussianBlue(gray, (5, 5), 0)

	#Perform Edge detection using Canny
	edges = cv.Canny(blurred, 50, 150)

	#Find Contour
	contours, _ = cv.findContours(edges, cv.RETR_TREE. cv.CHAIN_APPROX_SIMPLE)

	for cnt in contours:
		approx = cv.approxPolyDP(cnt, 0.02 * cv.arcLength(cnt, True), True)

	if len(approx) == 7: #Arrows typically have 7 sides
		cv.drawContours(image, [approx], 0, (0,255,0), 3)
		print("Arrow detected!")

		#Calculate bounding box
		x, y, w, h = cv.boundingRect(approx)
		perceived_width = max(w, h)

		#Find distance (Function to be implemented)
		distance = find_distance(perceived_width)
		print(f"Estimated Distance: {distance:.2f} cm")
	
	#Show the result
	cv.imread('Detected Arrow', image)
	cv.waitKey(0)
	cv.destroyAllWindows()

def find_distance(perceived_width):
	#Implement the function to calculate distance
	if perceived_width == 0:
		return float("Some error must have happend")
	return (REAL_ARROW_WIDTH * focal_length) / perceived_width

# Provide the path to your image
image_path = 'arrow.jpg'
detect_arrow(image_path)
