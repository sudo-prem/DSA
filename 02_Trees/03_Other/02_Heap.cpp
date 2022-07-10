#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
	int *arr;
	int size;
	int currSize;
	Heap(int s) : size(s + 1), currSize(1)
	{
		arr = new int[s + 1];
		arr[0] = -1;
	}
};

void Display(Heap *heap)
{
	for (int i = 1; i < heap->currSize; ++i)
		cout << heap->arr[i] << " ";
	cout << endl;
}

void Insert(Heap *heap, int value)
{
	if (heap->currSize == heap->size)
	{
		cout << "Heap OverFlow\n";
		return;
	}
	int i = heap->currSize;
	heap->arr[i] = value;
	heap->currSize++;
	while (i > 1 and heap->arr[i / 2] < value)
	{
		swap(heap->arr[i], heap->arr[i / 2]);
		i /= 2;
	}
}

void Delete(Heap *heap)
{
	if (heap->currSize == 1)
	{
		cout << "Heap UnderFlow\n";
		return;
	}
	// Swapping the root with the last element
	swap(heap->arr[1], heap->arr[heap->currSize - 1]);
	heap->currSize--;
	int i = 1, j = 2;
	while (j < heap->currSize and (heap->arr[i] < heap->arr[j] or (j + 1 < heap->currSize and heap->arr[i] < heap->arr[j + 1])))
	{
		if (j + 1 < heap->currSize and heap->arr[j + 1] > heap->arr[j])
			j += 1;
		swap(heap->arr[i], heap->arr[j]);
		i = j;
		j *= 2;
	}
}

// Regular Insertion happens from top to bottom,
// Regular deletion happens from bottom to top,
// Heapify happens from bottom to top, takes only O(n) time
void Heapify(Heap *heap)
{
	int n = heap->currSize - 1;
	while (n > 0)
	{
		if (n * 2 < heap->currSize)
		{
			int i{n}, j{n * 2};
			while (j < heap->currSize and (heap->arr[i] < heap->arr[j] or heap->arr[i] < heap->arr[j + 1]))
			{
				if (j + 1 < heap->currSize and heap->arr[j + 1] > heap->arr[j])
					j += 1;
				swap(heap->arr[i], heap->arr[j]);
				i = j;
				j *= 2;
			}
		}
		n--;
	}
}

void HeapSort(Heap *heap)
{
	Heapify(heap);
	int n = heap->currSize - 1, i{};
	while (n - i > 0)
	{
		Delete(heap);
		i++;
	}
	heap->currSize = n + 1;
}

void solve()
{
	vector<int> vec{10, 20, 30, 25, 5, 40, 35};
	// the constructor for heap creates array arr with 0th index to be -1, since we wont be using it
	Heap *heap1 = new Heap(vec.size());
	for (auto i : vec)
		Insert(heap1, i);
	cout << "Heap after Insertion: ";
	Display(heap1);
	cout << "Heap after Deletion: ";
	Delete(heap1);
	Display(heap1);
	cout << endl;

	Heap *heap2 = new Heap(vec.size());
	for (int i = 0; i < vec.size(); ++i)
		heap2->arr[i + 1] = vec[i];
	heap2->currSize = vec.size() + 1;
	cout << "Heap with random values: ";
	Display(heap2);
	cout << "Heapify: ";
	Heapify(heap2);
	Display(heap2);
	cout << "Heap Sort: ";
	HeapSort(heap2);
	Display(heap2);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t{1};
	// cin >> t;
	while (t--)
		solve();
	return 0;
}
