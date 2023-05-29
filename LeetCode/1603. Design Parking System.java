class ParkingSystem {
    int [] parkingSlots = new int[3];
    public ParkingSystem(int big, int medium, int small) {
       parkingSlots = new int[]{big,medium,small};
    }
    
    public boolean addCar(int carType) {
        if(parkingSlots[carType-1]>=1){
            parkingSlots[carType-1]--;
            return true;
        }
        return false;
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * boolean param_1 = obj.addCar(carType);
 */