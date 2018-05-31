//
// Created by igor on 22.05.18.
//

#include<Templates.h>
#include <iostream>

using namespace mytemplates;

class MockToStore{
public:
    MockToStore(int i){
        value=i;
    }
    int value;
};

bool myQuerry(MockToStore object) {
    return object.value==2;
}

int main(){



    Logger<std::string, std::ostream> testlogger(std::cout);
    testlogger.Debug("Debug1");


    MockToStore one(1);
    MockToStore two(2);
    std::vector<MockToStore> testvector{one, two};
    Repository<MockToStore> testrepo(testvector);
    std::vector<MockToStore> result;

    result=testrepo.MyFindBy(myQuerry);

    std::cout<<std::endl<<result[0].value<<std::endl;

    return 0;
}