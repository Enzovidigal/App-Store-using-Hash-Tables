#define	CAT_NAME_LEN	100
#define	APP_NAME_LEN	200
#define	VERSION_LEN 20
#define	UNIT_SIZE   4

struct app_info{
	char category[ CAT_NAME_LEN ]; // Name of category
	char app_name[ APP_NAME_LEN ]; // Name of the application
	char version[ VERSION_LEN ]; // Version number
	float size; // Size of the application
	char units[ UNIT_SIZE ]; // GB or MB
	float price; // Price in $ of the application
};

struct bst{ // A binary search tree
    struct app_info record; // Information about the application
    struct bst *left;  // Pointer to the left subtree
    struct bst *right;  // Pointer to the right subtree
};

struct categories{
    char category[ CAT_NAME_LEN ]; // Name of category
    struct bst *root;  // Pointer to root of search tree for this category
};

struct hash_table_entry{
   char app_name[ APP_NAME_LEN ]; // Name of the application
   struct bst *app_node; // Pointer to node in BST containing the application information
   struct hash_table_entry *next; // Next pointer for chain in separate chaining
};

//global variable used on recursive algorithms
extern int global_index;

//defined functions on bst.cc
bst* insert(bst* root, app_info appInfo);
void traversePrintApps(bst* root);
void traversePrintMax(bst* root, float rootMaxHeap);
float* traverse_heap(bst* root, float* heap_array);
void traversePriceFree(bst* root);
void free_bst(bst* root);

//defined functions on heap.cc
int node_counter(bst* root);
float* build_Max_Heap(float* heapArray, int n);
void max_heapify(float* heapArray, int i, int n);


//defined functions on prime.cc
bool testForPrime(int val);
void insertHT(hash_table_entry **t, bst* root, char* appName, int m);
hash_table_entry** hashArray(int m);
void freeHash(hash_table_entry** t, int m);
