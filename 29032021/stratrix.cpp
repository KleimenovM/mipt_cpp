//
// Created by kleim on 3/29/2021.
//

struct StrangeMatrix {
    int first_line[3];
    int second_line[3];
    int third_line[3];
};

StrangeMatrix transpose(StrangeMatrix m) {
    StrangeMatrix x{};
    int **lines = new int*[3];
    lines[0] = m.first_line;
    lines[1] = m.second_line;
    lines[2] = m.third_line;
    for (int i = 0; i < 3; i++){
        x.first_line[i] = lines[i][0];
        x.second_line[i] = lines[i][1];
        x.third_line[i] = lines[i][2];
    }
    /* for(int i = 0; i < 3; i++)
        delete lines[i]; */
    delete[] lines;

    return x;
}