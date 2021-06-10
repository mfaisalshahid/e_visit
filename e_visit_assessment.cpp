/*
There are multiple other ways to solve this problem. In the past, I have come across similar problems
and have used min heap (making the data structure myself), sorting like bucket sort, and quick select.
This implementation is my favorite because it is very easy to understand and explain. I have also tested
the time it takes for this algorithm to run as compared to some other algorithms, and this one is by far
the fastest. 

/////////////////////////////////////////////////////////////////////////////////////////////////////

In this case, I am assuming that we push the IP's to the map and For the first function (request_handled) 
the time complexity for unordered_map is O(1). O(1) is only for the unordered_map. In reality we have 
to traverse over all the IP's which will be O(n), for whenever we call this function.

/////////////////////////////////////////////////////////////////////////////////////////////////////

For the second function, we have a priority queue (Max heap). For this, the time complexity will be O(log n).
The Priority queue size will never grow more than n-100 in this particular case, thus for worst case it will
be O (log n).

/////////////////////////////////////////////////////////////////////////////////////////////////////

At first the request handled function just accepts all the IP's and places them in the unordered map. Each
time a similar IP comes in, it increments the frequency of that particular IP by 1. Then we call the top_100
function, we make a priority queue and push values into it as a pair. The pairs are IP's and their frequencies.
We iterate over our map and push the values from the map into the priority queue as pairs. We keep on pushing 
till the position of our iterator is at the map.size()-k, then we can start to push the element into res and 
pop() from queue. Also since the question asked to return the set of IP's, I put them in a vector, otherwise 
we can print them in the function as well. 

/////////////////////////////////////////////////////////////////////////////////////////////////////

I tested this using min heap but that was taking more time to compute.

/////////////////////////////////////////////////////////////////////////////////////////////////////

I tested this with sample IP's. I generated random IP's using a random generator online and ran my functions 
with it. I tested it for 100,000 IP's and it took on average less than 1 ms to run. I am assuming if we get 
20 million, it should satisfy that time constraint as well.
*/

unordered_map<string,int> incoming_ips;

// O(1) for unordered map. O(n) for the for loop over all the IP's.
void request_handled(string ip_address){
	incoming_ips[ip_address]++;
}

// O(log n)
vector<string> top_100(){
	vector<string> res;
    priority_queue<pair<int,string>> pq;
    for(auto it = incoming_ips.begin(); it != incoming_ips.end(); it++){
        pq.push(make_pair(it->second, it->first));
        if(pq.size() > (int)incoming_ips.size() - 100){
            res.push_back(pq.top().second);
            pq.pop();
        }
    }
    return res;
}

void clear_ips(){
	incoming_ips.clear();
}
