def identify_img(file_path, img_check):
    try:
        with open(file_path, 'rb') as file:
            file_contents = file.read()
            if img_check.encode() in file_contents:
                return True
    except FileNotFoundError:
        pass
    return False

print("\b")
img_file = input("Enter the name of the IMG file (with .IMG extension): ")

if img_file.lower().endswith((".img", ".IMG")):
    if identify_img(img_file, "TRUEVISION-XFILE"):
        print("It's a TGA file")
    elif identify_img(img_file, "IMG10"):
        print("\b")
        print("IMG using version 1.0")
        print("\b")
    elif identify_img(img_file, "IMG1.0.1"):
        print("\b")
        print("IMG using version 1.0.1")
        print("\b")
    else:
        print("IMG format not recognized")
        print("Maybe your IMG uses an different format, Then please contact BJNFNE on Discord\n")
else:
    print("Invalid IMG file extension. Please provide a file with .img extension.")
