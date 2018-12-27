# Nearby_Cab_Finder
 It is a program which has the user's location (i.e) Latitude and Longitude of the position and then there is a file cabs_data.json.
 The file cabs_data.json  stores the details and location s of all the cabs in the city.
 The program reads the location of each car from the json file and converts the radian to degree and checks if the distance of the cab ios less than 20km from the user's location using the "Great Circle Distance Formulae" and the program will produce a file named cars_near_you.json which holds the id and name of the cars which are in range of 20km from your location.
