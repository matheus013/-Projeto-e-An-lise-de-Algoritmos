#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9

struct Event {
  int distance;
  string type;
  double consumption;
};

typedef std::vector<Event> ve;
typedef std::vector<ve> vve;

bool can_simulate(const double fuel, const vector<Event> events) {
  double drive = events[0].consumption;
  double leak = 0;
  int previous_distance = 0;

  double remaining = fuel;

  for(vector<Event>::const_iterator it = events.begin() + 1; it != events.end(); ++it) {
    double rate = (drive / 100.0) + leak;

    remaining -= rate * (it->distance - previous_distance);

    previous_distance = it->distance;
    if(remaining >= 0 && it->type[0] == 'G' && it->type[1] == 'o') return true;
    if(remaining < 0) return false;

    if (it->type[0] == 'F') 
      drive = it->consumption;
    else if (it->type[0] == 'L') 
      ++leak;
    else if (it->type[0] == 'G' && it->type[1] == 'a')
      remaining = fuel;
    else if (it->type[0] == 'M')
      leak = 0;
  }

  return false;
}

int main() {
  vve all_events;

  ve events;

  Event current;

  while (cin >> current.distance) {
    cin >> current.type;
    if ((current.type[0] == 'G' && current.type[1] == 'a') || current.type[0] == 'F') { string tmp; cin >> tmp; }
    if (current.type[0] == 'F') {
      cin >> current.consumption;
      if (current.consumption == 0) 
        break;
    }
    events.push_back(current);
    if (current.type[0] == 'G' && current.type[1] == 'o') {
      all_events.push_back(events);
      events.clear();
    }
  }

  for(vve::const_iterator event = all_events.begin(); event != all_events.end(); ++event) {
    double low = 0.0, high = 10000.0, mid = 0.0, answer = 0.0;
    while(fabs(high - low) > EPS) {
      mid = (low + high) / 2.0;

      if (can_simulate(mid, *event)) {
        answer = mid; 
        high = mid;
      } else {
        low = mid;
      }
    }
    printf("%.3f\n", answer);
  }

  return 0;
}