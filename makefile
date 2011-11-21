all:
	g++ main.cpp ipaddress.cpp subnet.cpp -o subnet-tool

clean:
	rm -rf subnet-tool