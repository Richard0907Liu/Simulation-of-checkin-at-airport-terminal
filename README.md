# Simulation-of-waiting-queues

1. Two classes of service: first class and coach. Each class of service has a dedicated queue.
2. There are two service stations for first class and three for coach.
3. Each service station takes passengers from the corresponding queue; but if a first class service station is free and the 
   queue for coach is not empty then the service station serves passengers from the coach queue.
4. Passenger arrival times are random, but subject to average arrival times; for example, we get a first class passenger every 
   five minutes and a coach passenger every two minutes on average. Actual arrival times are random.
5. Passenger service times are also random, but subject to average service times; for example, first class passengers usually 
   require six minutes of service and coach passengers get on average 2 minutes of service. These are average times; actual times vary. 
   All times are measured in minutes.
6. The simulation starts with empty waiting queues and free service stations. At some point in time (usually 40 minutes prior to 
   departure time) the company closes the queues (no more passengers are admitted); then the simulation ends when all the queues are empty and all the service stations are free.
   
   
Inputs to the simulation:

1. The duration of the check in (make it arbitrarily long, do not worry about it being or not being realistic).
2. The coach average arrival rate, and average service rate.
3. The first class average arrival rate and average service rate.
