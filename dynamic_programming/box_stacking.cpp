/* 
 * Given a set of n types of rectangular 3-D boxes, where the i^th box has height h(i), width w(i) 
 * and depth d(i) (all real numbers). You want to create a stack of boxes which is as tall as 
 * possible, but you can only stack a box on top of another box if the dimensions of the 2-D 
 * base of the lower box are each strictly larger than those of the 2-D base of the higher box. 
 * 
 * Of course, you can rotate a box so that any side functions as its base. It is also allowed 
 * to use multiple instances of the same type of box.
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
using namespace std;

struct box{
    int l, b, h;
    box(int ll, int bb, int hh): l(ll), b(bb), h(hh){}
    friend ostream& operator<<(ostream &os, const box &b){
        os << "[" << b.l << "," << b.b << "," << b.h << "]";
        return os;
    }
};

struct boxCompare{ // sort boxes in set according to decreasing base areas
    bool operator() (const box &lhs, const box &rhs){
        return lhs.l * lhs.b > rhs.l * rhs.b;
    }
};

using set_box_t = set<box, boxCompare>;

inline void pprint(vector<box> &vb){
    std::copy(vb.begin(), vb.end(), std::ostream_iterator<box>(std::cout, "\n"));
}

bool canSitOnTop(box &b1, box &b2){
    return b1.l < b2.l && b1.b < b2.b;
}

vector<box> maxStackHeight(vector<box> &boxes){

    vector<int> maxHeight(boxes.size()); // denotes the maxHeight attainable with i-th box on top
    vector<int> boxUnder(boxes.size());  // denotes the box under the i-th box
    
    for(int i=0; i<boxes.size(); ++i){
        maxHeight[i] = boxes[i].h;
        boxUnder[i] = -1;
    }
    
    for(int i=1; i<boxes.size(); ++i){
        for(int j=0; j<i; ++j){
            if(canSitOnTop(boxes[i], boxes[j])){ 
                if( (maxHeight[j] + boxes[i].h) > maxHeight[i]){
                    maxHeight[i] = maxHeight[j] + boxes[i].h;
                    boxUnder[i] = j;
                }
            }
        }
    }
    
    vector<box> stack;
    cout << "Max stack height: " << maxHeight[maxHeight.size()-1] << endl;
    int topBox = maxHeight.size()-1;
    while(topBox != -1){
        stack.push_back(boxes[topBox]);
        topBox = boxUnder[topBox];
    }
    
    return stack;
}

set_box_t rotations(int l, int b, int h){
    set_box_t rot;
    
    rot.insert(box(max(l,b), min(l,b), h));
    rot.insert(box(max(h,b), min(h,b), l));
    rot.insert(box(max(l,h), min(l,h), b));
    return rot;
}


int main() {
    int sum, n, i;
    set_box_t boxes; // store all rotations of boxes in a set sorted by decreasing base area
    
    cout << "Input number of box-types:" << endl;
    cin >> n;
    cout << "Input box dimensions [l b h]:" << endl;
    for (int i=0; i<n; ++i){
        int l, b, h;
        cin >> l >> b >> h;
        set<box, boxCompare> rboxes = rotations(l, b, h);
        boxes.insert(rboxes.begin(), rboxes.end());
    }

    // copy sorted boxes into boxarr
    vector<box> boxarr;
    copy(boxes.begin(), boxes.end(), back_inserter(boxarr));

    vector<box> stack = maxStackHeight(boxarr);
    cout << "Box Stack: " << endl;
    pprint(stack);
}

