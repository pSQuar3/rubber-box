#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>
#include <numeric>

using std::vector;
using namespace std;

#define MY_MAX_INT 9999999999

double minimum_distance(vector<int> x, vector<int> y)
{
  double result = 0.0;
  long unsigned int num_vertex = x.size();
  vector<double> cost(num_vertex, MY_MAX_INT);
  auto cmp = [](pair<int, double> left, pair<int, double> right) { return (((left.second) > (right.second)) || (((left.second) == (right.second)) && ((left.first) > (right.first)))); };
  priority_queue<pair<int, double>, std::vector<pair<int, double>>, decltype(cmp)> my_queue(cmp);
  vector<bool> visited(num_vertex, false);
  cost[0] = 0.0;
  my_queue.push(make_pair(0, cost[0]));
  while (!my_queue.empty())
  {
	  int vertex_idx = my_queue.top().first;
	  my_queue.pop();
	  if (visited[vertex_idx] == false)
	  {
		  for (size_t i = 0; i < num_vertex; i++)
		  {

			  if ((vertex_idx != (int)i) && (visited[i] == false)) // Make sure we don't calculate the distance between the vertex and itself
			  {
				  double x_dist = x[vertex_idx] - x[i];
				  double y_dist = y[vertex_idx] - y[i];
				  double euclidean_distance = sqrt((x_dist*x_dist) + (y_dist*y_dist));
				  double new_cost = euclidean_distance;
				  if (cost[i] > new_cost)// 
				  {
					  cost[i] = new_cost;
					  my_queue.push(make_pair(i, cost[i]));
				  }
			  }
		  }
		  visited[vertex_idx] = true;
	  }
  }
  for (int i = 0; i < (int)cost.size(); i++)
  {
	  result += cost[i];
  }

  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
