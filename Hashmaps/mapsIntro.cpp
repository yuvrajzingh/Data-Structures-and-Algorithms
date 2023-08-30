#include<bits/stdc++.h>
using namespace std;

int main(){

    //creation
    unordered_map<string, int> m;
 
    //insertion ways

    //1
    pair<string, int> p1 = make_pair("Yuvraj", 3);
    m.insert(p1);

    //2
    pair<string, int> p2("Yuzi", 2);
    m.insert(p2);

    //3
    m["Mannu"] = 1;


    //what happens in this case
    m["Yuvraj"] = 2;  //the already existing key would be updated. It won't create a new pair. 

    //---------Thus keys should be unique


 
    //Search ways

    //1
    cout<<m["Mannu"] <<endl;

    //2
    cout<<m.at("Yuvraj") <<endl;

    //but
    // cout<<m.at("unknown") <<endl;  -------This will throw an error
    
    // cout<<m["unknown"]<<endl; -------This will return 0

    // cout<<m.at("unkown");  ---- Now this will also return 0


    //Size
    cout<<m.size()<<endl;
    
    //check presence
    cout<<m.count("Bro");//  will return 0 since key is absent
    cout<<m.count("Mannu"); // will return 1 since it is present (returns a bool)


    //erase or delete
    m.erase("Mannu");
    cout<< m.size() <<endl;  //length is dec by 1

    for(auto i:m){
        cout<< i.first <<" " << i.second <<endl;  //first=key second=value
    }   

    



    return 0;
}