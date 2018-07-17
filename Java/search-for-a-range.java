//  Search for a Range

class Untitled {
	private int lowerBound(int[] arr, int val) {
		int i = 0, j = arr.length-1;
		while (i < j) {
			int mid = i + (j-i) / 2;
			if (arr[mid] < val)
				i = mid + 1;
			else
				j = mid;
		}
		return i;
	}
	
	private int upperBound(int[] arr, int val) {
		int i = 0, j = arr.length-1;
		while (i < j) {
			int mid = i + (j-i) / 2;
			if (arr[mid] <= val)
				i = mid + 1;
			else
				j = mid;
		}
		return i;
	}
		
	public static void main(String[] args) {
		int[] arr = {1,2,3,3,3,3,4};
		int lower = lowerBound(arr, 3);
		int upper = upperBound(arr, 3);
		if (lower==arr.length || arr[lower]!=3) {
			lower = -1;
			upper = -1;
		}
		System.out.println(lower);
		System.out.println(upper);
	}
}