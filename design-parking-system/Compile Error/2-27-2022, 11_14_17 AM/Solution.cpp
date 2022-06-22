// https://leetcode.com/problems/design-parking-system

class ParkingSystem {
public:
    vector<int> v;
    ParkingSystem(int big, int medium, int small) {
        v = {small,medium,big};
    }
    
    bool addCar(int carType) {
        if(v[carType]-1>0){
            (v[carType]--;
            return true;
        }
             return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */