"""
Programmer: Trenton Fales
Class: CptS 111-02, Spring 2017
Programming Assignment #5
4/5/17

Description: This program computes simple statistics about a road
trip using Google Maps API. This program reads in US locations 
from an input file and writes new information and statistics
to a new file. The statistics include number of waypoints,
number of days on the roadtrip, total miles traveled, longest
roadtrip distance between waypoints, longest roadtrip days at
one waypoint, average roadtrip distance between waypoints, and
average roadtrip days at one waypoint.
"""

### The following code is for the Google Maps API

import urllib.request

def format_city_string(city_str):
    city_str = city_str.replace(",", "")
    city_str = city_str.replace(" ", "+")
    return city_str
  
def build_query(origin, dest):
    query_base = "http://maps.googleapis.com/maps/api/distancematrix/json?origins="    
    query = query_base + origin
    query += "&destinations="
    query += dest
    query += "&mode=driving&sensor=false"
    return query
    
def extract_distance(results_str):
    '''
    Extracts the distance in meters from the JSON response.
    '''
    index = results_str.find("distance")
    results_str = results_str[index:]
    index = results_str.find("value")
    results_str = results_str[index:]
    index = results_str.find(":")
    results_str = results_str[index + 2:]
    index = results_str.find(r"\n")
    results_str = results_str[:index]
    dist = int(results_str)
    return dist
    
def get_distance(city1, city2):
    '''
    Accepts 2 strings representing cities in the U.S.
    Returns the integer distance in meters between city1 and city2
    '''
    city1 = format_city_string(city1)
    city2 = format_city_string(city2)
    
    query = build_query(city1, city2)

    web_obj = urllib.request.urlopen(query)
    # web_obj.read() returns an array of bytes, need to convert to a string
    results_str = str(web_obj.read())
    web_obj.close()
    
    dist = extract_distance(results_str)
    return dist

def explain_program(): # Explains the program
    '''
    This function will be used to explain the function of the program.
    '''
    print("Welcome to the road trip analyzer program, utilizing Google Maps! Roadtrip origin, destination, waypoints, and number of days spent at each waypoint will be read in from a file. The program writes to an output file the distance in miles between each waypoint on the trip and statistics about the trip. Enjoy!")
    

def convert_meters_to_miles(dist): #Converts the meters given from Google Maps API to miles
    '''
    This function will convert the distance between waypoints from meters to miles.
    '''
    miles = dist * .000621371
    return miles

def roadtrip_origin(): # Determines where the roadtrip begins
    '''
    This function will determine the origin of the roadtrip.
    '''
    print()
    print("Reading in roadtrip stop information from florida_roadtrip.txt...")
    print()
    roadtrip = open("florida_roadtrip.txt", "r")
    origin = roadtrip.readline() # First line from file
    print("Roadtrip origin:", origin.strip())
    roadtrip.close()
    
def roadtrip_destination(): # Determines where the roadtrip ends
    '''
    This function will determine the destination of the roadtrip.
    '''
    roadtrip = open("florida_roadtrip.txt", "r")
    destination = roadtrip.readlines()
    for line in destination:
        if line == 'Gainesville, FL':
            print("Roadtrip destination:", line)
    print()
    print("Writing stop stats to florida_roadtrip_stats.txt...")
    print("Closing files...")
    roadtrip.close

def waypoints(): # Determines all of the stops between origin and destination
    '''
    This function determines all of the waypoints.
    '''
    roadtrip = open("florida_roadtrip.txt", "r")
    waypoint = roadtrip.readlines()
    location = 2 # First waypoint on line 2
    day = 3 # Number of days spent at location starts on line 3
    while location < 30:
        stop = waypoint[location].strip()
        time = waypoint[day].strip()
        print("Processing waypoint %s (%s days)..." % (stop, time))
        location += 3 # 3 lines until the next location
        day += 3
    roadtrip.close()
    
def calc_num_stops():
    '''
    This function will calculate the number of stops there are.
    '''
    roadtrip = open("florida_roadtrip.txt", "r")
    waypoint = roadtrip.readlines()
    location = 2 # First waypoint on line 2
    day = 3 # Number of days spent at location starts on line 3
    count = 0
    while location < 30:
        stop = waypoint[location].strip()
        time = waypoint[day].strip()
        location += 3 # 3 lines until the next location
        day += 3
        count += 1
    return count
    roadtrip.close()
    
def calc_num_days():
    '''
    This function will calculate the number of days spent on the trip.
    '''
    roadtrip = open("florida_roadtrip.txt", "r")
    day = roadtrip.readlines()
    # The number of days at each stop is located on every 3rd line in the file
    # Convert string to integer
    num_days = int(day[3]) + int(day[6]) + int(day[9]) + int(day[12]) + int(day[15]) + int(day[18]) + int(day[21]) + int(day[24]) + int(day[27]) + int(day[30])
    return num_days
    roadtrip.close()

def calc_total_miles():
    '''
    This funcion will calculate the total miles traveled on the trip.
    '''
    dist1 = get_distance("Spokane, WA", "Yellowstone National Park, WY")
    miles1 = convert_meters_to_miles(dist1)
    dist2 = get_distance("Yellowstone National Park, WY", "Grand Teton National Park, WY")
    miles2 = convert_meters_to_miles(dist2)
    dist3 = get_distance("Grand Teton National Park, WY", "Salt Lake City, UT")
    miles3 = convert_meters_to_miles(dist3)
    dist4 = get_distance("Salt Lake City, UT", "Bryce Canyon National Park, UT")
    miles4 = convert_meters_to_miles(dist4)
    dist5 = get_distance("Bryce Canyon National Park, UT", "Grand Canyon, AZ")
    miles5 = convert_meters_to_miles(dist5)
    dist6 = get_distance("Grand Canyon, AZ", "Surprise, AZ")
    miles6 = convert_meters_to_miles(dist6)
    dist7 = get_distance("Surprise, AZ", "Carlsbad Caverns National Park, NM")
    miles7 = convert_meters_to_miles(dist7)
    dist8 = get_distance("Carlsbad Caverns National Park, NM", "San Antonio, TX")
    miles8 = convert_meters_to_miles(dist8)
    dist9 = get_distance("San Antonia, TX", "New Orleans, LA")
    miles9 = convert_meters_to_miles(dist9)
    dist10 = get_distance("New Orleans, LA", "Panama City, FL")
    miles10 = convert_meters_to_miles(dist10)
    dist11 = get_distance("Panama City, FL", "Gainesville, FL")
    miles11 = convert_meters_to_miles(dist11)
    miles = miles1 + miles2 + miles3 + miles4 + miles5 + miles6 + miles7 + miles8 + miles9 + miles10 + miles11
    return miles

def calc_longest_dist():
    '''
    This function will calculate the longest distance between waypoints.
    '''
    dist1 = get_distance("Spokane, WA", "Yellowstone National Park, WY")
    dist2 = get_distance("Yellowstone National Park, WY", "Grand Teton National Park, WY")
    dist3 = get_distance("Grand Teton National Park, WY", "Salt Lake City, UT")
    dist4 = get_distance("Salt Lake City, UT", "Bryce Canyon National Park, UT")
    dist5 = get_distance("Bryce Canyon National Park, UT", "Grand Canyon, AZ")
    dist6 = get_distance("Grand Canyon, AZ", "Surprise, AZ")
    dist7 = get_distance("Surprise, AZ", "Carlsbad Caverns National Park, NM")
    dist8 = get_distance("Carlsbad Caverns National Park, NM", "San Antonio, TX")
    dist9 = get_distance("San Antonia, TX", "New Orleans, LA")
    dist10 = get_distance("New Orleans, LA", "Panama City, FL")
    dist11 = get_distance("Panama City, FL", "Gainesville, FL")
    if dist1 > dist2 and dist1 > dist3 and dist1 > dist4 and dist1 > dist5 and dist1 > dist6 and dist1 > dist7 and dist1 > dist8 and dist1 > dist9 and dist1 > dist10 and dist1 > dist11:
        miles1 = convert_meters_to_miles(dist1)
        return miles1
    elif dist2 > dist1 and dist2 > dist3 and dist2 > dist4 and dist2 > dist5 and dist2 > dist6 and dist2 > dist7 and dist2 > dist8 and dist2 > dist9 and dist2 > dist10 and dist2 > dist11:
        miles2 = convert_meters_to_miles(dist2)
        return miles2
    elif dist3 > dist1 and dist3 > dist2 and dist3 > dist4 and dist3 > dist5 and dist3 > dist6 and dist3 > dist7 and dist3 > dist8 and dist3 > dist9 and dist3 > dist10 and dist3 > dist11:
        miles3 = convert_meters_to_miles(dist3)
        return miles3
    elif dist4 > dist1 and dist4 > dist2 and dist4 > dist3 and dist4 > dist5 and dist4 > dist6 and dist4 > dist7 and dist4 > dist8 and dist4 > dist9 and dist4 > dist10 and dist4 > dist11:
        miles4 = convert_meters_to_miles(dist4)
        return miles4
    elif dist5 > dist1 and dist5 > dist2 and dist5 > dist3 and dist5 > dist4 and dist5 > dist6 and dist5 > dist7 and dist5 > dist8 and dist5 > dist9 and dist5 > dist10 and dist5 > dist11:
        miles5 = convert_meters_to_miles(dist5)
        return miles5
    elif dist6 > dist1 and dist6 > dist2 and dist6 > dist3 and dist6 > dist4 and dist5 > dist6 and dist6 > dist7 and dist6 > dist8 and dist6 > dist9 and dist6 > dist10 and dist6 > dist11:
        miles6 = convert_meters_to_miles(dist6)
        return miles6
    elif dist7 > dist1 and dist7 > dist2 and dist7 > dist3 and dist7 > dist4 and dist7 > dist5 and dist7 > dist6 and dist7 > dist8 and dist7 > dist9 and dist7 > dist10 and dist7 > dist11:
        miles7 = convert_meters_to_miles(dist7)
        return miles7
    elif dist8 > dist1 and dist8 > dist2 and dist8 > dist3 and dist8 > dist4 and dist8 > dist5 and dist8 > dist6 and dist8 > dist7 and dist8 > dist9 and dist8 > dist10 and dist8 > dist11:
        miles8 = convert_meters_to_miles(dist8)
        return miles8
    elif dist9 > dist1 and dist9 > dist2 and dist9 > dist3 and dist9 > dist4 and dist9 > dist5 and dist9 > dist6 and dist9 > dist7 and dist9 > dist8 and dist9 > dist10 and dist9 > dist11:
        miles9 = convert_meters_to_miles(dist9)
        return miles9
    elif dist10 > dist1 and dist10 > dist2 and dist10 > dist3 and dist10 > dist4 and dist10 > dist5 and dist10 > dist6 and dist10 > dist7 and dist10 > dist8 and dist10 > dist9 and dist10 > dist11:
        miles10 = convert_meters_to_miles(dist10)
        return miles10
    else:
        miles11 = convert_meters_to_miles(dist11)
        return miles11
    
def calc_longest_days():
    '''
    This function will calculate the longest number of days spent at one location.
    '''
    roadtrip = open("florida_roadtrip.txt", "r")
    day = roadtrip.readlines()
    # The number of days at each stop is located on every 3rd line in the file
    # Convert string to integer
    if int(day[3]) > int(day[6]) and int(day[3]) > int(day[9]) and int(day[3]) > int(day[12]) and int(day[3]) > int(day[15]) and int(day[3]) > int(day [18]) and int(day[3]) > int(day[21]) and int(day[3]) > int(day[24]) and int(day[3]) > int(day[27]) and int(day[3]) > int(day[30]):
        return int(day[3])
    elif int(day[6]) > int(day[3]) and int(day[6]) > int(day[9]) and int(day[6]) > int(day[12]) and int(day[6]) > int(day[15]) and int(day[6]) > int(day[18]) and int(day[6]) > int(day[21]) and int(day[6]) > int(day[24]) and int(day[6]) > int(day[27]) and int(day[6]) > int(day[30]):
        return int(day[6])
    elif int(day[9]) > int(day[3]) and int(day[9]) > int(day[6]) and int(day[9]) > int(day[12]) and int(day[9]) > int(day[15]) and int(day[9]) > int(day[18]) and int(day[9]) > int(day[21]) and int(day[9]) > int(day[24]) and int(day[9]) > int(day[27]) and int(day[9]) > int(day[30]):
        return int(day[9])
    elif int(day[12]) > int(day[3]) and int(day[12]) > int(day[6]) and int(day[12]) > int(day[9]) and int(day[12]) > int(day[15]) and int(day[12]) > int(day[18]) and int(day[12]) > int(day[21]) and int(day[12]) > int(day[24]) and int(day[12]) > int(day[27]) and int(day[12]) > int(day[30]):
        return int(day[12])
    elif int(day[15]) > int(day[3]) and int(day[15]) > int(day[6]) and int(day[15]) > int(day[9]) and int(day[15]) > int(day[12]) and int(day[15]) > int(day[18]) and int(day[15]) > int(day[21]) and int(day[15]) > int(day[24]) and int(day[15]) > int(day[27]) and int(day[15]) > int(day[30]):
        return int(day[15])
    elif int(day[18]) > int(day[3]) and int(day[18]) > int(day[6]) and int(day[18]) > int(day[9]) and int(day[18]) > int(day[12]) and int(day[18]) > int(day[15]) and int(day[18]) > int(day[21]) and int(day[18]) > int(day[24]) and int(day[18]) > int(day[27]) and int(day[18]) > int(day[30]):
        return int(day[18])
    elif int(day[21]) > int(day[3]) and int(day[21]) > int(day[6]) and int(day[21]) > int(day[9]) and int(day[21]) > int(day[12]) and int(day[21]) > int(day[15]) and int(day[21]) > int(day[18]) and int(day[21]) > int(day[24]) and int(day[21]) > int(day[27]) and int(day[21]) > int(day[30]):
        return int(day[21])
    elif int(day[24]) > int(day[3]) and int(day[24]) > int(day[6]) and int(day[24]) > int(day[9]) and int(day[24]) > int(day[12]) and int(day[24]) > int(day[15]) and int(day[24]) > int(day[18]) and int(day[24]) > int(day[21]) and int(day[24]) > int(day[27]) and int(day[24]) > int(day[30]):
        return int(day[24])
    elif int(day[27]) > int(day[3]) and int(day[27]) > int(day[6]) and int(day[27]) > int(day[9]) and int(day[27]) > int(day[12]) and int(day[27]) > int(day[15]) and int(day[27]) > int(day[18]) and int(day[27]) > int(day[21]) and int(day[27]) > int(day[24]) and int(day[27]) > int(day[30]):
        return int(day[27])
    else:
        return int(day[30])
    roadtrip.close()
    
def calc_average_days():
    '''
    This function will calculate the average number of days spent at each stop.
    '''
    roadtrip = open("florida_roadtrip.txt", "r")
    day = roadtrip.readlines()
    avg_days = (int(day[3]) + int(day[6]) + int(day[9]) + int(day[12]) + int(day[15]) + int(day[18]) + int(day[21]) + int(day[24]) + int(day[27]) + int(day[30]))/10
    return avg_days
    roadtrip.close()
    
def calc_average_dist():
    '''
    This function will calculate the average distance between stops.
    '''
    dist1 = get_distance("Spokane, WA", "Yellowstone National Park, WY")
    miles1 = convert_meters_to_miles(dist1)
    dist2 = get_distance("Yellowstone National Park, WY", "Grand Teton National Park, WY")
    miles2 = convert_meters_to_miles(dist2)
    dist3 = get_distance("Grand Teton National Park, WY", "Salt Lake City, UT")
    miles3 = convert_meters_to_miles(dist3)
    dist4 = get_distance("Salt Lake City, UT", "Bryce Canyon National Park, UT")
    miles4 = convert_meters_to_miles(dist4)
    dist5 = get_distance("Bryce Canyon National Park, UT", "Grand Canyon, AZ")
    miles5 = convert_meters_to_miles(dist5)
    dist6 = get_distance("Grand Canyon, AZ", "Surprise, AZ")
    miles6 = convert_meters_to_miles(dist6)
    dist7 = get_distance("Surprise, AZ", "Carlsbad Caverns National Park, NM")
    miles7 = convert_meters_to_miles(dist7)
    dist8 = get_distance("Carlsbad Caverns National Park, NM", "San Antonio, TX")
    miles8 = convert_meters_to_miles(dist8)
    dist9 = get_distance("San Antonia, TX", "New Orleans, LA")
    miles9 = convert_meters_to_miles(dist9)
    dist10 = get_distance("New Orleans, LA", "Panama City, FL")
    miles10 = convert_meters_to_miles(dist10)
    dist11 = get_distance("Panama City, FL", "Gainesville, FL")
    miles11 = convert_meters_to_miles(dist11)
    avg_dist = (miles1 + miles2 + miles3 + miles4 + miles5 + miles6 + miles7 + miles8 + miles9 + miles10 + miles11) / 11
    return avg_dist
    
def write_stats(count, num_days, miles, avg_dist, avg_days):
    '''
    This function will write the stats of the trip to a new file.
    '''
    roadtrip = open("florida_roadtrip_stats.txt", "w")
    florida_roadtrip = open("florida_roadtrip.txt", "r")
    location = florida_roadtrip.readlines()
    dist1 = get_distance("Spokane, WA", "Yellowstone National Park, WY")
    miles1 = convert_meters_to_miles(dist1)
    print(location[0].strip() + " to " + location[2].strip() + ": %.2f miles" % (miles1), file=roadtrip)
    
    dist2 = get_distance("Yellowstone National Park, WY", "Grand Teton National Park, WY")
    miles2 = convert_meters_to_miles(dist2)
    print(location[2].strip() + " to " + location[5].strip() + ": %.2f miles" % (miles2), file=roadtrip)
    
    dist3 = get_distance("Grand Teton National Park, WY", "Salt Lake City, UT")
    miles3 = convert_meters_to_miles(dist3)
    print(location[5].strip() + " to " + location[8].strip() + ": %.2f miles" % (miles3), file=roadtrip)
    
    dist4 = get_distance("Salt Lake City, UT", "Bryce Canyon National Park, UT")
    miles4 = convert_meters_to_miles(dist4)
    print(location[8].strip() + " to " + location[11].strip() + ": %.2f miles" % (miles4), file=roadtrip)
    
    dist5 = get_distance("Bryce Canyon National Park, UT", "Grand Canyon, AZ")
    miles5 = convert_meters_to_miles(dist5)
    print(location[11].strip() + " to " + location[14].strip() + ": %.2f miles" % (miles5), file=roadtrip)
    
    dist6 = get_distance("Grand Canyon, AZ", "Surprise, AZ")
    miles6 = convert_meters_to_miles(dist6)
    print(location[14].strip() + " to " + location[17].strip() + ": %.2f miles" % (miles6), file=roadtrip)
    
    dist7 = get_distance("Surprise, AZ", "Carlsbad Caverns National Park, NM")
    miles7 = convert_meters_to_miles(dist7)
    print(location[17].strip() + " to " + location[20].strip() + ": %.2f miles" % (miles7), file=roadtrip)
    
    dist8 = get_distance("Carlsbad Caverns National Park, NM", "San Antonio, TX")
    miles8 = convert_meters_to_miles(dist8)
    print(location[20].strip() + " to " + location[23].strip() + ": %.2f miles" % (miles8), file=roadtrip)
    
    dist9 = get_distance("San Antonia, TX", "New Orleans, LA")
    miles9 = convert_meters_to_miles(dist9)
    print(location[23].strip() + " to " + location[26].strip() + ": %.2f miles" % (miles9), file=roadtrip)
    
    dist10 = get_distance("New Orleans, LA", "Panama City, FL")
    miles10 = convert_meters_to_miles(dist10)
    print(location[26].strip() + " to " + location[29].strip() + ": %.2f miles" % (miles10), file=roadtrip)
    
    dist11 = get_distance("Panama City, FL", "Gainesville, FL")
    miles11 = convert_meters_to_miles(dist11)
    print(location[29].strip() + " to " + location[32].strip() + ": %.2f miles\n" % (miles11), file=roadtrip)
    
    print("***Road trip stats***", file=roadtrip)
    print("Number of waypoints on roadtrip: %d" % (count), file=roadtrip)
    print("Number of days on roadtrip: %d" % (num_days), file=roadtrip)
    print("Total miles traveled on roadtrip: %.2f miles" % (miles), file=roadtrip)
    dist = calc_longest_dist()
    print("Longest roadtrip distance between waypoints is: %d miles" % (dist), file=roadtrip)
    day = calc_longest_days()
    print("Longest roadtrip days at one waypoint is: %d days" % (day), file=roadtrip)
    print("Average roadtrip distance between waypoints is: %.2f miles" % (avg_dist), file=roadtrip)
    print("Average roadtrip days at one waypoint: %.2f days" % (avg_days), file=roadtrip)
    
    roadtrip.close()
    
def main():
    '''
    Drives the program.
    '''
    explain_program()   
    roadtrip_origin()
    waypoints()
    roadtrip_destination()
    count = calc_num_stops()
    days = calc_num_days()
    miles = calc_total_miles()
    calc_longest_dist()
    calc_longest_days()
    avg_dist = calc_average_dist()
    avg_days = calc_average_days()
    write_stats(count, days, miles, avg_dist, avg_days)
    
main()





























