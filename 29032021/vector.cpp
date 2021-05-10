//
// Created by kleim on 3/29/2021.
//

struct vect {
    int x;
    int y;
    int z;
};

vect sum(vect a, vect b){
    vect c{};
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;
    return c;
}

int main(){
    return 0;
}

