import cv2 as cv
import numpy as np

def find_distance(perceived_width):
	#Implement the function to calculate distance
	pass

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


# Provide the path to your image
image_path = 'arrow.jpg'
detect_arrow(image_path)
