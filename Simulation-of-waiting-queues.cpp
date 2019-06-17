#include<iostream>
#include<math.h>
#include<vector>
#include<random>
#include<stdlib.h>
#include<time.h>
using namespace std;

struct queue_node {
	int sequence;
	int arrival_time;
	int service_time;
	struct queue_node *next;
};
typedef struct queue_node node;

node *coach_front = NULL;
node *first_front = NULL;
int static number = 1; // count number for coach or first

node *enqueue(node *front, int arrival, int service) {
	node *new_node, *ptr = NULL;
	ptr = front;
	
	new_node = (node *)malloc(sizeof(node));
	if (!new_node) {
		cout << "Fail to arrange the memory" << endl;
		exit(0);
	}
	new_node->arrival_time = arrival;
	new_node->service_time = service;
	new_node->next = NULL;

	if (front == NULL) {
		new_node->next = front;
		front = new_node;
	}
	else {
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		if (ptr->next == NULL)
			ptr->next = new_node;
		else {  // this would not be use in this assn
			new_node->next = ptr->next;
			ptr->next = new_node;
		}
	}
	return front;
}

node *dequeue(node *front) {
	node *top;
	int arrival_time, service_time;
	
	if (front != NULL) {
		top = front;
		arrival_time = front->arrival_time;
		service_time = front->service_time;
		front = front->next;
		free(top);
		cout << " dequeue- "<<  number << ": " << arrival_time << ", " << service_time << endl;
		number++;
		return front;
	}
	else
		cout << " Cannot dequeue!" << endl;

}
 
node *getNodeFromCoach(node *first_front, node *coach_front) {
	if (coach_front->next->next == NULL)
	{
		first_front = coach_front->next;
		coach_front->next = NULL;
	}
	else if (coach_front->next->next != NULL) {
		first_front = coach_front->next;
		coach_front->next = coach_front->next->next;
		first_front->next = NULL;
	}
	else
		cout << "Cannot get a node from coach" << endl;

	return first_front;
}

void printQueue(node *front) {
	// node *ptr = coach_front;
	node *ptr = front;
	cout << "Passenagers in line: " << endl;
	int number = 0;
	while (ptr != NULL)
	{
		number++;
		cout << number << ": ";
		cout << ptr->arrival_time << ", ";
		cout << ptr->service_time << endl;
		ptr = ptr->next;
		
	}
	cout << endl;
}

int main() {
	/*
	Arrival rate
	get coach passenger average 2 min, get first class passenger average 5 min
	*/
	int all_coach_passenage = 150;
	int all_first_passenage = 100;

	float duration; // Total mins to check in
	float coach_arrival_rate;
	float first_arrival_rate;  
	float coach_service_rate; // mins
	float first_service_rate; // mins

	cout << "== Module 03 Assignment: Programming Assignment 1 ==" << endl;
	cout << "The duration of the check in (min): "; cin >> duration;
	duration = duration * 60;

	cout << "The coach average arrival rate (min): "; cin >> coach_arrival_rate;
	cout << "The coach average service rate (min): "; cin >> coach_service_rate;
	
	cout << "The first class average arrival rate (min): "; cin >> first_arrival_rate;
	cout << "The frist class average service rate (min): "; cin >> first_service_rate;

	cout << endl << endl;
	int arrival_coach = all_coach_passenage;
	int arrival_first = all_first_passenage;

	


	vector<int> coach_arrival_list;  // default 150 x 2 x 60 sec= 18000
	vector<int> first_arrival_list;  // default 50 x 5 x 60 = 15000
	
	int rand_time;

	// For coach arrival time, average 2 min
	srand(time(NULL)); // Initialize radom seed
	int coach_total_time = 0;
	for (int i = 1; i <= arrival_coach; i++) {
		rand_time = (rand() % 180 + 33) * coach_arrival_rate/2;
		coach_arrival_list.push_back(rand_time);
		//cout << i << ": " << rand_time << endl;
		coach_total_time += rand_time;
	}

	cout << "Coach class total arrival interval: " << coach_total_time << endl;;
	cout << "The average of arrival time: " << coach_total_time / arrival_coach << endl;
	cout << "The size of the vector: " << coach_arrival_list.size() << endl;
	// For first class arrival time, average 5 min
	srand(time(NULL));// Initialize radom seed
	int first_total_time = 0; // about 15000, 
	for (int i = 1; i <= arrival_first; i++) {
		rand_time = (rand() % 450 + 85) * first_arrival_rate / 5;
		first_arrival_list.push_back(rand_time);
		//cout << i << ": " << rand_time << endl;
		first_total_time += rand_time;
	}

	cout << "First class total arrival interval: " << first_total_time << endl;;
	cout << "The average of arrival time: " << first_total_time / arrival_first << endl;

	/* 
	Service rate 
	service every coach passenage average 2 min, service first class passenage 6 min on average
	
	*/
	vector<int> coach_service_time;  // default 150 x 2 x 60 sec= 18000
	vector<int> first_service_time;  // default 50 x 6 x 50 = 18000

	// Coach passenage service for average 2 min 
	cout << endl<< "==============================" << endl;
	cout << "Coach passenage service time" << endl;

	int coach_total_service_time = 0; // about 18000 under 150 persons
	srand(time(NULL));; // Initialize radom seed
	for (int i = 1; i <= arrival_coach; i++) {
		//rand_time = (rand() % 180 + 30) * coach_service_rate;
		rand_time = (rand() % 90 + 30) * coach_service_rate;
		coach_service_time.push_back(rand_time);
		//cout << i << ": " << rand_time << endl;
		coach_total_service_time += rand_time;
	}
	
	cout << "Coach class total service time: " << coach_total_service_time << endl;;
	cout << "The average of service time: " << coach_total_service_time / arrival_coach << endl;

	// first passenage service for average 6 min 
	cout << endl << "==============================" << endl;
	cout << "First passenage service time" << endl;

	int first_total_service_time = 0; // about 18000 under 150 persons
	srand(time(NULL)); // Initialize radom seed
	for (int i = 1; i <= arrival_first; i++) {
		//rand_time = (rand() % 180 + 275) * first_service_rate;
		rand_time = (rand() % 30 + 60) * first_service_rate;
		first_service_time.push_back(rand_time);
		//cout << i << ": " << rand_time << endl;
		first_total_service_time += rand_time;
	}

	cout << "First class total service time: " << first_total_service_time << endl;;
	cout << "The average of service time: " << first_total_service_time / arrival_first << endl;

	int coach_persons = 1, first_persons = 1, coach_in_line = 0, first_in_line = 0;
	int coach_arrival_sec = 0, first_arrival_sec = 0;
	int coach_service_sec = 0, first_service_sec = 0; // initalize sec not to dequeue ( if sec == 0)
	float coach_total_service_sec = 0, first_total_service_sec = 0;
	int coach_avg_waiting_time = 0, coach_max_waiting_time = 0, first_avg_waiting_time = 0, first_max_waiting_time = 0;;
	int coach_max_length = 0, first_max_length = 0;
	int first_serve_coach = 0;
	//bool coach_service_start = false, first_service_start = false;
	int seconds = 0;
	while (seconds <= duration) {  // while(seconds <= check_in_time) // set duration of check in 

		if (coach_persons == (arrival_coach + 1) - first_serve_coach) // Avoid enqueuing when without any vector 
			; // end the enqueue
		else if (coach_arrival_sec == coach_arrival_list[0]) { // if a vector is NULL, this code will be crashed
			coach_front= enqueue(coach_front, coach_arrival_list[0], coach_service_time[0]);
			coach_arrival_list.erase(coach_arrival_list.begin()); // delete first position in arrival list
			coach_service_time.erase(coach_service_time.begin()); // delete first position in service list
			coach_arrival_sec = 0;
			coach_persons++;  // number of next costumer
			coach_in_line++;
			if (coach_in_line > coach_max_length)
				coach_max_length = coach_in_line;
			// coach_service_start = true;
			cout << "Coach class, adding a customer" << endl;
			cout << coach_in_line << " persons in a line." << endl;
			//printQueue(coach_front);
	
		}
		
		// For first class enqueue
		if (first_persons == (arrival_first + 1) + first_serve_coach) // Avoid enqueuing when without any vector
			; // end the enqueue
		else if (first_arrival_sec == first_arrival_list[0]) {
			first_front = enqueue(first_front, first_arrival_list[0], first_service_time[0]);
			first_arrival_list.erase(first_arrival_list.begin()); // delete first position in arrival list
			first_service_time.erase(first_service_time.begin()); // delete first position in service list
			first_arrival_sec = 0;
			first_persons++; // number of next costumer
			first_in_line++;
			if (first_in_line > first_max_length)
				first_max_length = first_in_line;
			// first_service_start = true;
			cout << "First class,  adding a customer" << endl;
			cout << first_in_line << " persons in a line." << endl;
			//printQueue(first_front);
		}

		// For service station-- dequene
		// coach dequeue, first dequene
		// (coach_persons-1), (first_persons-1) => really persons in a queue
		
		if(coach_in_line > 0) {
			coach_service_sec++;
			if (coach_service_sec == coach_front->service_time) {
				coach_total_service_sec += coach_front->service_time;
				// avg and max waiting time
				coach_avg_waiting_time = (coach_total_service_sec / (coach_persons-1))/3;
				if (coach_service_sec > coach_max_waiting_time)
					coach_max_waiting_time = (coach_service_sec)/3;
				cout << "==== Coach service station ==== " << endl;;
				coach_front = dequeue(coach_front);
				cout << "Current average waiting time: " << coach_avg_waiting_time << ", max waiting time: " << coach_max_waiting_time << endl;
				cout << "Coach total process seconds: " << coach_total_service_sec << endl;
				cout << "Senconds since open check-in: " << seconds << endl;
				cout << "The rate of occupancy: " << (coach_total_service_sec / seconds) << endl << endl;
				coach_in_line--;
				coach_service_sec = 0;
				// if (coach_in_line == 0)
			}
		}
		
		if (first_in_line > 0) {
			first_service_sec++;
			if (first_service_sec == first_front->service_time) {
				first_total_service_sec += first_front->service_time;
				// avg and max waiting time
				first_avg_waiting_time = (first_total_service_sec / (first_persons - 1))/2;
				if (first_service_sec > first_max_waiting_time)
					first_max_waiting_time = (first_service_sec)/2;
				cout << "==== First service station ==== " << endl;;
				first_front = dequeue(first_front);
				cout << "Current average waiting time: " << first_avg_waiting_time << ", max waiting time: " << first_max_waiting_time << endl;
				cout << "First class total process secnds: " << first_total_service_sec << endl;
				cout << "Senconds since open check-in: " << seconds << endl;
				cout << "Rate of occupancy: " << (first_total_service_sec / seconds) << endl << endl;
				first_in_line--;
				first_service_sec = 0;
				// if (coach_in_line == 0)
			}
		}								// There are two customer in coach line
		else if (first_in_line == 0 && coach_in_line > 1) {  // first class station service a coach passenager
			cout << endl << "===== First-class station serves a coach passenager ====" << endl << endl;
			first_front = getNodeFromCoach(first_front, coach_front);

			coach_in_line--;
			first_in_line++;

			coach_persons--;
			first_persons++;

			first_serve_coach++;
		}

		seconds++;
		coach_arrival_sec++;
		first_arrival_sec++;
	}


	cout << "======  The final information  ====== " << endl;
	cout << " The duration of the simulation (min): " << seconds / 60 << endl;
	cout << "== The coach class == " << endl;
	cout << "The maximum length (persons): " << coach_max_length << endl;
	cout << "The average waiting time (sec): " << coach_avg_waiting_time << endl;
	cout << "The maximum waiting time (sec): " << coach_max_waiting_time << endl;
	cout << "The rate of occupancy (%): " << (coach_total_service_sec / seconds) << endl;
	//cout << endl << "The passenagers didn't ckeck in in time (excluding no arrival passenagers): " << endl;
	//printQueue(coach_front);

	cout << "== The first class == " << endl;
	cout << "The maximum length (persons): " << first_max_length << endl;
	cout << "The average waiting time (sec): " << first_avg_waiting_time << endl;
	cout << "The maximum waiting time (sec): " << first_max_waiting_time << endl;
	cout << "The rate of occupancy (%): " << (first_total_service_sec / seconds) << endl;
	//cout << endl << "The passenagers didn't ckeck in in time (excluding no arrival passenagers): " << endl;
	//printQueue(first_front);

	return 0; 
} 
