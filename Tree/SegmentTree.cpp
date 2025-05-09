    vector<int> sgt;

    void constructSgt(vector<int>& heights, int st, int end, int pos = 0) {
        if (st == end) {
            sgt[pos] = st;
            return;
        }
        int mid = st + (end - st) / 2;
        constructSgt(heights, st, mid, pos * 2 + 1);
        constructSgt(heights, mid + 1, end, pos * 2 + 2);

        sgt[pos] = (heights[sgt[pos * 2 + 1]] >= heights[sgt[pos * 2 + 2]]) ? sgt[pos * 2 + 1] : sgt[pos * 2 + 2];
    }

    int query(vector<int>& heights, int ql, int qr, int st, int end, int idx) {
        if (qr < st || ql > end) return 0; 
        if (ql <= st && end <= qr) return sgt[idx];

        int mid = st + (end - st) / 2;

        return (query(heights, ql, qr, st, mid, idx * 2 + 1) + query(heights, ql, qr, mid + 1, end, idx * 2 + 2));
    }
