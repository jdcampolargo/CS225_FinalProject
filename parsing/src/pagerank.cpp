#include "../airport/include/airport.h"
#include "../include/graph.h"
#include "../include/node.h"
#include "../src/node.cpp"
#include "../include/pagerank.h"
#include <cmath>
#include <exception>
#include <iostream>
#include <vector>
#include <string>


void PageRank::makeAdjMatrix(unsigned dim, double damping) {
    dimension_ = dim; //store dim
    //resize adj matrix
    //adjacency_matrix_.resize(num,vector<double>(dim));

    //use damping factor to generate the require extra factor
    damping_factor_ = (1 - damping) / dimension_;

    //adjust adj matrix according to pagerank alg
    for(int i = 0; i < dimension_; i++){
        double sum = 0;
        for(int j = 0; j < dimension_; j++){
            sum += adjacency_matrix_[j][i];
        }     
        if(sum == 0){
            //double z = 1/dimension_;
            for(int j = 0; j < dimension_; j++){
                adjacency_matrix_[j][i] = 1/(double)dimension_;
            }              
        } else {
            for(int j = 0; j < dimension_; j++){
                adjacency_matrix_[j][i] = (adjacency_matrix_[j][i] / sum) * damping + damping_factor_;
            }             
        }
    }
}

vector<double> PageRank::makeVector() {
    vector<double> initial;
    initial.resize(dimension_);
    for(unsigned i = 0; i < dimension_; i++){
        initial[i] = rand();
    }
    return initial;
}

vector<double> PageRank::calculaterRank(vector<double> initial, size_t iterations, bool normalize) {
     //vectors which stores the intermediate result
    vector<double> holder1 = initial;
    vector<double> holder2 = initial;
    for(int t = 0; t < iterations; t++){
        for(int i = 0; i < dimension_; i++){
            //initialize the vector
            holder2[i] = 0;
            //calculate product of adjmatrix and vector 
            for(int j = 0; j < dimension_; j++){
                holder2[i] += adjacency_matrix_[i][j] * holder1[j];

                if(normalize) {
                    double sum = 0;
                    //perform norm 2 normalize
                    for(vector<double>::iterator it = holder2.begin(); it != holder2.end(); ++it)
                        sum += (*it)*(*it);
                    double normalize = sqrt(sum);

                    for(int n = 0; n < dimension_; n++){
                        holder2[n] = holder2[n] / normalize;
                    }
                }

            }     
        }
        holder1 = holder2;
    }
    //store result in the pagerank obj
    pr_ = holder1;
    return pr_;
}

// void Pagerank::popularAirports(size_t topNum) {
// vector<int> airport;
//     vector<double> largest;
//     largest.resize(topNum);
//     airport.resize(topNum);

//     int position = 0;

//     //figure out the index of the important airport in the pagerank result vector
//     for(int i = 0; i < topNum; i++){
//         double max = 0;
//         for(auto it = pr_.begin(); it != pr_.end(); ++it){
//             if(*it > max){
//                 bool flag = true;
//                 //check if the current airport is already on the list of the important airport
//                 for(auto temp = largest.begin(); temp != largest.end(); ++temp){
//                     if(*temp == *it) {
//                         flag = false;
//                         break;
//                     }
//                 }
//                 if(flag)
//                     max = *it;
//             }
//         }
//         largest[position] = (max);
//         position++;
//     }

//     position = 0;
//     //using the index and the name_list to find out the relating airport id
//     for(int i = 0; i < topNum; i++){
//         int count = 0;
//         for(auto it = pr_.begin(); it != pr_.end(); ++it){
//             if(largest[i] == *it){
//                 airport[position] = popular_airports[count];
//                 position++;
//             }
//             count++;
//         }
//     }
// }


void PageRank::printAdjMatrix() {
      cout<<"adj matrix"<<endl;
    cout<<"      ";
    for(int i = 0; i < dimension_; i++){
        cout<<popular_airports[i];
        cout<<"           ";
    }
    cout<<"\n";
    for(int i = 0; i < dimension_; i++){
        cout<<popular_airports[i];
        cout<<"  ";
        for(int j = 0; j < dimension_; j++){
            cout<<adjacency_matrix_[i][j];
            cout<<"  ";
        } 
        cout<<"\n";
    }
    cout<<"\n";
}

void PageRank::printResults() {
    cout<<"page rank result\n"; 
    cout<<" ID      value\n"; 
    for(int i = 0; i < dimension_; i++){
        cout<<popular_airports[i];
        cout<<" ";
        cout<<pr_[i];
        cout<<"\n";
    }
    cout<<"\n";
}