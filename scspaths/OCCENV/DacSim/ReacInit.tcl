
# init special eiv
extvar set dei*comsta 3
extvar set dei*ln*sta 3
extvar set dei*spy 6

# init for Door
extvar set dei*DO*fault 0
extvar set dei*DO*open 0
extvar set dei*DO*close 1
extvar set dei*DO*lock 1
extvar set dei*DO*intr 0

# init for IntrusionDetector
extvar set dei*ID*fault 0
extvar set dei*ID*state 0

# init for Camera
extvar set dei*CA*fault 0
extvar set dei*CA*state 1
extvar set dei*CA*rec 0
extvar set aei*CA*angle 45
extvar set aei*CA*zoom 25

# init for FireDetector
extvar set dei*FD*fault 0
extvar set dei*FD*smoke 0

# init for Sprinkler
extvar set dei*SP*fault 0
extvar set dei*SP*state 0

# init for Valve Section
extvar set dei*POWERVA*fault 0
extvar set dei*POWERVA*open 0
extvar set dei*POWERVA*close 1
extvar set dei*POWERVA*lock 0

# init for PressureSensor Section
extvar set dei*POWERPS*fault 0
extvar set aei*POWERPS*press 2.2


# ping
extvar set dei*ping 1

# for simu
extvar set deiSIMUEvtNum* 0
extvar set deiSIMUAlmThr* 0
extvar set deiSIMUPeriod* 5000
