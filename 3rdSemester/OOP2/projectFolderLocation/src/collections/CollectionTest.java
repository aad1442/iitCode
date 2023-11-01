package collections;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;

public class CollectionTest {
	private static final String[] colors = { "Magenta", "Red", "White", "Blue", "Cyan" };
	private static final String[] removeColors = { "Red", "White", "Blue" };

	public CollectionTest() {
		List<String> list = new ArrayList<String>();
		List<String> removeList = new ArrayList<String>();

		for (String color : colors) {
			list.add(color);
		}
		for(String color: removeColors) {
			removeList.add(color);
		}
		
		System.out.println("ArrayList: ");
		for(int i=0;i<list.size();i++) {
			System.out.printf("%s ",list.get(i));
		}
		
		removeColor(list,removeList);
		System.out.println("\n\nArraylist after calling removeColors: ");
		
		for(String color: list) {
			System.out.printf("%s ",color);
		}
		

	}
	
	private void removeColor(Collection<String>collection1, Collection<String> collection2) {
		Iterator <String> iterator = collection1.iterator();
		
		while(iterator.hasNext()) {
			if(collection2.contains(iterator.next())) {
				iterator.remove();
			}
		}
			
	}
	
	public static void main(String args[]) {
		new CollectionTest();
	}

}
