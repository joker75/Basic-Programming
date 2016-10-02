# Bus Monitor
# CURRENT ISSUE: AttributeError: module 'urllib' has no attribute 'open'
import urllib

# Define variables
candidates = ['1865', '1383']
daves_lat= 41.980262

# Define functions
def distance (lat1, lat2):
	'Return distance in miles between two lats'
	return 69*abs(lat1-lat2)
	
def monitor():
	u = urllib.open('http://ctabustracker.com/bustime/map/getBusesForRoute.jsp?route=22')
	doc = parse(u)
	for bus in doc.findall ('bus'):
		busid = bus.findtext('id')
		if busid in candidates:
			lat = float(bus.findtext('lat'))
			dis = distance(lat, daves_lat)
			print (busid,'miles')
	print ('-'*10)
	
import time
while True:
	monitor()
	time.sleep(60)