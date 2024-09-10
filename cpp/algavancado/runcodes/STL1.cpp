#include<iostream>
#include<map>
// #include<string>

int main(int argc, char ** argv) {
	int n_casos;
	
	std::cin >> n_casos;

	for (int i = 0; i < n_casos; i++) {
		int n_testes;
		std::cin >> n_testes;
		std::map<std::string, int> task_map;
		
		for (int j = 0 ; j < n_testes ; j++) {
			std::string tech;
			int days;
			std::cin >> tech >> days;

			task_map[tech] = days;

		}

		std::string required_tech;
		int required_days;
		std::cin >> required_days >> required_tech;


		if (task_map[required_tech] <= required_days  && task_map[required_tech ] > 0) {
			std::cout << "Case " << i+1 << ": Ufa!" << std::endl;
		} else if (task_map[required_tech] <= required_days + 5  && task_map[required_tech] > 0) {
			std::cout << "Case " << i+1 << ": Atrasado" << std::endl;
		} else {
			std::cout << "Case " << i+1 << ": Deu ruim! Va trabalhar" << std::endl;
		}
	}
}
