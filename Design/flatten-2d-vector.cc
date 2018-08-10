//  Flatten 2D Vector

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        vec_begin = vec2d.begin();
        vec_end = vec2d.end();
        row = vec_begin;
        if (row != vec_end)
            col = row->begin();
    }

    int next() {
        int res = *col;
        col ++;
        return res;
    }

    bool hasNext() {
        if (row == vec_end)  return false;
        if (col == row->end()) {
            row ++;
            for (; row!=vec_end && row->size()==0; row++);
            if (row == vec_end) return false;
            col = row->begin();
        }
        return true;
    }
    
private:
    vector<vector<int>>::iterator row;
    vector<int>::iterator col;
    vector<vector<int>>::iterator vec_begin, vec_end;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
