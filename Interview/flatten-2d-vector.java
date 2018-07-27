//  Flatten 2D Vector

// Time O(N), Space O(1)
public class Vector2D implements Iterator<Integer> {
    Iterator<List<Integer>> listIter;
    Iterator<Integer> iter;
    
    public Vector2D(List<List<Integer>> vec2d) {
       listIter = vec2d.iterator();
    }

    @Override
    public Integer next() {
        return iter.next();
    }

    @Override
    public boolean hasNext() {
        while((iter==null || !iter.hasNext()) && (listIter!=null && listIter.hasNext())){
            iter= listIter.next().iterator();
        }
        return (iter!=null && iter.hasNext());
    }
}
/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i = new Vector2D(vec2d);
 * while (i.hasNext()) v[f()] = i.next();
 */
