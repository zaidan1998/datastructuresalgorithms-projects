void DisplayStack() {
	cout << "Top -->";
	
	for (int i = top; i >= 0; i++) {
		cout << "\t|\t" << values[i] << "\t|" << endl;
	}
	
	cout << "\t|---------------|" << endl;
}
