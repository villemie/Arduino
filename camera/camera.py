#!/usr/bin/env python3
import serial
import subprocess
import sys, os
import time
import datetime
import dropbox
from dropbox.exceptions import ApiError, AuthError
resolutions = ["-r 320x240","-r 640x480","-r 1280x720","-r 1920x1080"]
arduinoSerial = '/dev/ttyACM0';
TOKEN = '' #Token of dropbox app
def get_name():
    name = datetime.datetime.now()
    name = name.strftime("%Y%m%d_%H%M%S")
    name = name + ".jpg"
    return name
def to_dropbox(localfile):
    
    # Check that access tocken added
    if (len(TOKEN) == 0):
        sys.exit("ERROR: Missing access token. "
                 "try re-generating an access token from the app console at dropbox.com.")

    # Create instance of a Dropbox class, which can make requests to API
    print("Creating a Dropbox object...")
    dbx = dropbox.Dropbox(TOKEN)

    # Check that the access token is valid
    try:
        dbx.users_get_current_account()
    except AuthError as err:
        sys.exit("ERROR: Invalid access token; try re-generating an "
                 "access token from the app console at dropbox.com.")

    # Specify upload path
    uploadPath = '/' + localfile

    # Read in file and upload
    with open(localfile, 'rb') as f:
        print("Uploading " + localfile + " to Dropbox as " + uploadPath + "...")

        try:
            dbx.files_upload(f.read(), uploadPath)
        except ApiError as err:
            # Check user has enough Dropbox space quota
            if (err.error.is_path() and
                    err.error.get_path().error.is_insufficient_space()):
                sys.exit("ERROR: Cannot upload; insufficient space.")
            elif err.user_message_text:
                print(err.user_message_text)
                sys.exit()
            else:
                print(err)
                sys.exit()



# Delete file
def deleteLocal(file):
    os.system("rm " + file)
    


if __name__ == '__main__':
    ser = serial.Serial(arduinoSerial, 9600, timeout=1000)
    ser.flush()

    while True:
        #if take photo button is pressed in arduino, Linux gets three digits number which states settings for picture and starts code after if below
        #First digit indicates resolution
        #Second digit is waiting time before taking the picture
        #Third digit means saving location 
        if ser.in_waiting > 1:
            line = ser.readline().decode('utf-8').rstrip() #Read digits from serial port
            print(line)
            time.sleep(int(line[1]))                       #Sleep/timer
            name = get_name()                            #Get name/time for picture
            subprocess.Popen(["fswebcam", resolutions[int(line[0])], name]) #Taking the picture
            #Sending picture to dropbox
            if (int(line[2])==1):
                time.sleep(2)                            #Waiting for picture to be ready before starting
                to_dropbox(name)
                deleteLocal(name)


