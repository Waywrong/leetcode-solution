//  Moving Average from Data Stream

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        max_slide_size = size;
    }
    
    double next(int val) {
        double res = 0;
        slide.push_back(slide.size()>0 ? slide[slide.size()-1]+val : val);
        if (slide.size() <= max_slide_size)
            res = slide[slide.size()-1] / (double)slide.size();
        else {
            res = (slide[slide.size()-1] - slide[slide.size()-1-max_slide_size]) / (double)max_slide_size;
            slide.erase(slide.begin());
        }
        return res;
    }
    
private:
    vector<long long> slide;
    int max_slide_size;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */