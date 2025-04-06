import math

"""For the simplicity of the promblem, I am assuming the camera has great FOV and when the red circle 
    went out of sight, the red circle will be directly beneath the Camera"""

# Function to calculate distance
def get_distance(x1, y1, z1, x2, y2, z2):
    return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2 + (z1 - z2) ** 2)

# Function to make new frame of refernce(center of rover as origin)
def new_frame(x, y, z, offset):
    distance = round(abs(get_distance(x, y, z, 0, 0, 0)))

    #unit distance
    unitX = x / distance
    unitY = y / distance

    # new co-ordinate in new frame of reference
    new_x = round(x + (offset * unitX), 2)
    new_y = round(y + (offset * unitY), 2)
    new_z = z  # z remains the same

    return new_x, new_y, new_z, distance

# Function to print distance before and after adjusting reference
def print_distances(x, y, z, new_x, new_y, new_z, offset, original_distance):

    # New camera origin in adjusted frame
    camera_new_x = round(offset * (x / original_distance), 2)
    camera_new_y = round(offset * (y / original_distance), 2)

    # Distance from new camera origin to marker in new frame
    dist_after = get_distance(new_x, new_y, new_z, camera_new_x, camera_new_y, 0)
    print(f"Distance after adjustment (new origin to marker): {round(dist_after, 2)} cm")

# Main program
if __name__ == "__main__":
    # get co-ordinate
    x, y, z = input("Enter coordinates (x y z): ").split()
    x, y, z = int(x), int(y), int(z)
    offset = 55

    new_x, new_y, new_z, original_distance = new_frame(x, y, z, offset)

    print(f"\nDistance before adjustment (camera to marker): {round(original_distance, 2)} cm")

    # Output the new marker coordinates
    print(f"\nNew Position of marker in rover's reference frame: ({new_x}, {new_y}, {new_z})")

    # Show distance before and after the reference frame adjustment
    print_distances(x, y, z, new_x, new_y, new_z, offset, original_distance)
