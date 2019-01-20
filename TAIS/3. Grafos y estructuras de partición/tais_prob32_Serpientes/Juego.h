#include <vector>
#include <queue>

class Juego {

public:

	Juego(std::vector<int> const & t, int K) : disTo(t.size(), 0), marked(t.size(), false) {

			bfs(t, 0, K);
	}

	int caminoMinimo(int i) { return disTo[i]; }

private:

	std::vector<int> disTo;
	std::vector<bool> marked;

	void bfs(std::vector<int> const & t, int vOrg, int dado) {

		std::queue<int> qV;
		marked[vOrg] = true;
		disTo[vOrg] = 0;
		qV.push(vOrg);

		while (!qV.empty()) {

			int v = qV.front();
			qV.pop();
			
			int i = 1;

			while (i <= dado && i + v < t.size()) {

				if (!marked[t[i + v]]) {

					marked[t[i + v]] = true;
					disTo[t[i + v]] = disTo[v] + 1;
					qV.push(t[i + v]);
				}

				++i;
			}
			

		}
	}
};
