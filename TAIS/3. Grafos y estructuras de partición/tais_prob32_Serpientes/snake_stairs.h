// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#ifndef SNAKE_STAIRS_H
#define SNAKE_STAIRS_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

#include <vector>
#include <queue>

class snake_stairs {

	std::vector<int> dist_to;
	std::vector<bool> marked;

public:

	snake_stairs(std::vector<int> const & t, int K) : dist_to(t.size(), 0), marked(t.size(), false) { bfs(t, 0, K); }

	int min_way(int i) const { return dist_to[i]; }

private:

	void bfs(std::vector<int> const & t, int v_org, int K) {

		std::queue<int> qv;

		marked[v_org] = true;
		dist_to[v_org] = 0;

		qv.push(v_org);

		while (!qv.empty()) {

			int v = qv.front();
			qv.pop();

			int i = 1;

			while (i <= K && v + i < t.size()) {

				if (!marked[t[v + i]]) {

					marked[t[v + i]] = true;
					dist_to[t[v + i]] = dist_to[v] + 1;
					qv.push(t[v + i]);
				}

				++i;
			}
		}
	}
};

#endif
