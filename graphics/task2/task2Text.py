import cv2


def main():
    img = cv2.imread("text.bmp", cv2.CV_LOAD_IMAGE_COLOR)  # Read image file
    img = cv2.GaussianBlur(img, (3, 3), 0)
    img = cv2.Laplacian(img, 0)
    cv2.threshold(img, 50, 255, cv2.THRESH_BINARY, img)
    cv2.imwrite("output.bmp", img)

    cv2.namedWindow('Display Window', cv2.WINDOW_NORMAL)        # Create window for display
    cv2.imshow('Display Window', img)         # Show image in the window
    cv2.moveWindow('Display Window', 1, 1)
    print ("size of image: ", img.shape)      # print size of image
    cv2.waitKey(0)                           # Wait for keystroke
    cv2.destroyAllWindows()                  # Destroy all windows

main()
