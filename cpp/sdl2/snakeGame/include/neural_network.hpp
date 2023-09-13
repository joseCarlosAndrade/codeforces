#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include<eigen3/Eigen/Dense>
#include<iostream>
#include<vector>

#define EULER 2.71828

namespace NeuralNetwork {

typedef enum {WEIGHTS, BIAS} NNData;

class SingleNetwork {
    private:
        const int _n_input, _n_output;
        Eigen::MatrixXf _w0, _b0;
    
    public:
        SingleNetwork();
        SingleNetwork(const int n_inputs, const int n_outputs, bool random=true) :   
            _n_input(n_inputs),
            _n_output(n_outputs)
        {
        // _w0 = Eigen::Matrix<float, (int)n_outputs, n_inputs>::Ones(_n_output, _n_input);
        // _w0 = Eigen::MatrixXf(n_outputs, n_inputs);
        // _b0 = Eigen::MatrixXf(n_outputs, 1);

        if (random) {
            _w0 = Eigen::MatrixXf::Random(n_outputs, n_inputs)*2; // generates random values between -2 and 2
            _b0 = Eigen::MatrixXf::Random(n_outputs, 1)*2;
        }
        else {
            _w0.setOnes();
            _b0.setOnes(); 
        }
    }

    Eigen::MatrixXf calculateOutput(Eigen::MatrixXf input);
    std::vector<float> calculateOutput(std::vector<float> input);
    void fillMatrices(std::string w_file_name, std::string b_file_name);
    // void fill_matrices(float*w_array, float*b_array);
    void flushCurrentData();
    void saveBestNetwork();

    Eigen::MatrixXf getData(NNData data_to_get);

};

typedef unsigned int CONTAINER_SIZE;

class NetworkContainer {
    private:
        std::vector<SingleNetwork> networks;
        CONTAINER_SIZE  n_networks;

        const int _n_input, _n_output;
    
    public:
        NetworkContainer(const int n_inputs, const int n_outputs) :
            _n_input(n_inputs), _n_output(n_outputs) {
            n_networks = 1;

        }
        NetworkContainer(CONTAINER_SIZE size_t, const int n_inputs, const int n_outputs) : 
            n_networks(size_t), _n_input(n_inputs), _n_output(n_outputs) 
            {
            assert(size_t!=0);

            networks.reserve(size_t);
            for (int i = 0; i < size_t; i++) {
                networks.push_back(SingleNetwork(n_inputs, n_outputs)); // initializes each network randomly

            }

            // _networks = new  NeuralNetwork::SingleNetwork() [ size_t]; // TODO: verify memory allocation success
            // // instance a lot of networks
            // for (int i = 0; i < size_t; i++) {
            //     _networks[i](n_inputs, n_outputs);
            // }
        }
        ~NetworkContainer() {
           
        }

        SingleNetwork * getNeuralNetwork(int index) {
            assert(index >= 0 && index <n_networks);

            return &networks[index];
        }
        
        void printAllNetworks () {
            std::vector<SingleNetwork>::iterator iterator;
            iterator = networks.begin();
            
            while(iterator != networks.end()) {
                std::cout << "Printing information on network: " << iterator - networks.begin() << std::endl
                << "Weights: " << std::endl << iterator->getData(WEIGHTS) << std::endl <<std::endl
                << "Bias: " << std::endl << iterator->getData(BIAS) << std::endl <<std::endl;

                iterator++;
            }
        }    
        
};

}

#endif