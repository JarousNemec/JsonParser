#include <iostream>
#include<algorithm>
#include <map>

using namespace std;

map<string,string> ParseJson(string json){

    //1. delete all useful chars
    json.erase(remove(json.begin(), json.end(), '"'), json.end());
    json.erase(0, 2);
    json.erase(json.length() - 2, 2);

    //2. replace all double dots by line
    replace(json.begin(), json.end(), ':', ','); // replace all 'x' to 'y'

    //3. add line to end of string for easier parsing
    json += ",";

    //4. split by , and save data to string map

    int startIndex = 0;
    int distance = json.find(',');
    string key;
    string value;
    int pointer = 0;
    map<string, string> jsonMap;

    while(distance != -1){
        string temp = json.substr(startIndex, distance - startIndex);
        startIndex = distance+1;
        distance = json.find(',', startIndex);
        if((pointer % 2) == 0){
            key = temp;
        }
        else{
            value = temp;
        }
        jsonMap[key] = value;
        pointer++;
    }

    return jsonMap;
}

int main() {
    string sampleJson = "[{\"PartitionKey\":\"1\",\"RowKey\":\"1\",\"state\":false}]";
    map<string, string> jsonMap = ParseJson(sampleJson);

    // print result values
    cout << jsonMap["PartitionKey"] << endl;
    cout << jsonMap["RowKey"] << endl;
    cout << jsonMap["state"] << endl;
    return 0;
}



