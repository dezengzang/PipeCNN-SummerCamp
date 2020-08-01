#include "../device/hw_param.cl"

#define NUM_CONFIG_ITEM  25

/*
// VGG-16 Configuration
unsigned layer_config[][NUM_CONFIG_ITEM] = {{0,
							224, 224, 3, 3, 3, 3, 64, 64,
							0,
							224, 224, 64, 1, 1, 0, 1,
							0, 224, 224, 64, 0, 0,
							0,
							1},//Layer-1 (conv1_1)
							{0,
							224, 224, 64, 3, 3, 64, 64, 64,
							1,
							224, 224, 64, 1, 1, 0, 1,
							1, 112, 112, 64, 2, 2,
							0,
							0},//Layer-2 (conv1_2)
							{0,
							112, 112, 64, 3, 3, 64, 128, 128,
							0,
							112, 112, 128, 1, 1, 0, 1,
							0, 112, 112, 128, 0, 0,
							0,
							1},//Layer-3 (conv2_1)
							{0,
							112, 112, 128, 3, 3, 128, 128, 128,
							1,
							112, 112, 128, 1, 1, 0, 1,
							1, 56, 56, 128, 2, 2,
							0,
							0},//Layer-4 (conv2_2)
							{0,
							56, 56, 128, 3, 3, 128, 256, 256,
							0,
							56, 56, 256, 1, 1, 0, 1,
							0, 56, 56, 256, 0, 0,
							0,
							1},//Layer-5 (conv3_1)
							{0,
							56, 56, 256, 3, 3, 256, 256, 256,
							1,
							56, 56, 256, 1, 1, 0, 1,
							0, 56, 56, 256, 0, 0,
							0,
							0},//Layer-6 (conv3_2)
							{0,
							56, 56, 256, 3, 3, 256, 256, 256,
							0,
							56, 56, 256, 1, 1, 0, 1,
							1, 28, 28, 256, 2, 2,
							0,
							1},//Layer-7 (conv3_3)
							{0,
							28, 28, 256, 3, 3, 256, 512, 512,
							1,
							28, 28, 512, 1, 1, 0, 1,
							0, 28, 28, 512, 0, 0,
							0,
							0},//Layer-8  (conv4_1)
							{0,
							28, 28, 512, 3, 3, 512, 512, 512,
							0,
							28, 28, 512, 1, 1, 0, 1,
							0, 28, 28, 512, 0, 0,
							0,
							1},//Layer-9  (conv4_2)
							{0,
							28, 28, 512, 3, 3, 512, 512, 512,
							1,
							28, 28, 512, 1, 1, 0, 1,
							1, 14, 14, 512, 2, 2,
							0,
							0},//Layer-10 (conv4_3)
							{0,
							14, 14, 512, 3, 3, 512, 512, 512,
							0,
							14, 14, 512, 1, 1, 0, 1,
							0, 14, 14, 512, 0, 0,
							0,
							1},//Layer-11  (conv5_1)
							{0,
							14, 14, 512, 3, 3, 512, 512, 512,
							1,
							14, 14, 512, 1, 1, 0, 1,
							0, 14, 14, 512, 0, 0,
							0,
							0},//Layer-12  (conv5_2)
							{0,
							14, 14, 512, 3, 3, 512, 512, 512,
							0,
							14, 14, 512, 1, 1, 0, 1,
							1, 7, 7, 512, 2, 2,
							0,
							2},//Layer-13  (conv5_3)    Note: for last conv layer, outputs are write to fc buffer
							{1,
							28, 28, 512, 7, 7, 512, 4096, 4096,
							2,
							4, 4, 4096, 7, 0, 0, 1,
							0, 4, 4, 4096, 0, 0,
							0,
							3},//Layer-14  (fc6)							
							{1,
							4, 4, 4096, 1, 1, 4096, 4096, 4096,
							3,
							4, 4, 4096, 1, 0, 0, 1,
							0, 4, 4, 4096, 0, 0,
							0,
							2},//Layer-15  (fc7)
							{1,
							4, 4, 4096, 1, 1, 4096, 1024, 1024,
							2,
							4, 4, 1024, 1, 0, 0, 0,
							0, 4, 4, 1024, 0, 0,
							0,
							3}//Layer-16  (fc8)		
							};

char precision_config[][3] ={{7,  0, -2},//Layer-1
							{ 8, -2, -5},//Layer-2
							{ 8, -5, -5},//Layer-3
							{ 8, -5, -6},//Layer-4
							{ 7, -6, -7},//Layer-5
							{ 8, -7, -7},//Layer-6
							{ 8, -7, -7},//Layer-7
							{ 8, -7, -6},//Layer-8
							{ 8, -6, -5},//Layer-9
							{ 8, -5, -5},//Layer-10
							{ 9, -5, -4},//Layer-11
							{ 9, -4, -3},//Layer-12
							{ 8, -3, -2},//Layer-13
							{ 8, -2,  0},//Layer-14
							{ 7,  0,  2},//Layer-15
							{ 7,  2,  2}//Layer-16
							};

unsigned input_config[4] = {224, 224, 3, 16};

//unsigned output_config[3] = {112, 112, 64};//Layer-2

unsigned output_config[3] = {1, 1, 1024};//Layer-16
*/

/*
// Alexnet Configuration batch=16
unsigned layer_config[][NUM_CONFIG_ITEM] = {{0,
							227, 227, 3, 11, 11, 3, 96, 96,
							0,
							55, 55, 96, 4, 0, 0, 1,
							1, 27, 27, 96, 3, 2,
							1,
							1},//Layer-1
							{0,
							27, 27, 96, 5, 5, 48, 256, 256,
							0,
							27, 27, 256, 1, 2, 1, 1,
							1, 13, 13, 256, 3, 2,
							1,
							1},//Layer-2
							{0,
							13, 13, 256, 3, 3, 256, 384, 384,
							0,
							13, 13, 384, 1, 1, 0, 1,
							0, 13, 13, 384, 0, 0,
							0,
							1},//Layer-3
							{0,
							13, 13, 384, 3, 3, 192, 384, 384,
							1,
							13, 13, 384, 1, 1, 1, 1,
							0, 13, 13, 384, 0, 0,
							0,
							0},//Layer-4
							{0,
							13, 13, 384, 3, 3, 192, 256, 256,
							0,
							13, 13, 256, 1, 1, 1, 1,
							1, 6, 6, 256, 3, 2,
							0,
							2},//Layer-5  Note: for last conv layer, outputs are write to fc buffer
							{1,
							24, 24, 256, 6, 6, 256, 4096, 4096,  // Note: The input size (dim1/dim2) is the combined data size (batched)
							2,
							4, 4, 4096, 6, 0, 0, 1,
							0, 4, 4, 4096, 0, 0,
							0,
							3},//Layer-6 fc
							{1,
							4, 4, 4096, 1, 1, 4096, 4096, 4096,
							3,
							4, 4, 4096, 1, 0, 0, 1,
							0, 4, 4, 4096, 0, 0,
							0,
							2},//Layer-7 fc
							{1,
							4, 4, 4096, 1, 1, 4096, 1024, 1024,
							2,
							4, 4, 1024, 1, 0, 0, 0,
							0, 4, 4, 1024, 0, 0,
							0,
							3}//Layer-8 fc
							};

char precision_config[][3] ={{8,  0, -4},//Layer-1
							{ 8,  0, -2},//Layer-2
							{ 8,  0, -1},//Layer-3
							{ 8, -1, -1},//Layer-4
							{ 8, -1, -1},//Layer-5
							{11, -1,  0},//Layer-6
							{10,  0,  2},//Layer-7
							{10,  2,  2}//Layer-8
							};

unsigned input_config[5] = {227, 227, 3, 16}; //original image size(dim1, dim2, dim3), batch size

//unsigned output_config[3] = {27, 27, 96};//Layer-1

//unsigned output_config[3] = {6, 6, 256};//Layer-5

//unsigned output_config[3] = {1, 1, 4096};//Layer-6

unsigned output_config[3] = {1, 1, 1024};//Layer-8  Note: only one result is extracted and verified

*/

/* ------------------------------------------------------------------------
 * 
 * The following configurations are used for development and test only
 *
 * ------------------------------------------------------------------------
 */

 /*	
// Test FC only (AlexNet fc6-fc8)
unsigned layer_config[][NUM_CONFIG_ITEM] = {{1,
							6, 6, 256, 6, 6, 256, 4096, 4096,  // Note: The input size (dim1/dim2) is the combined data size (batched)
							2,
							1, 1, 4096, 6, 0, 0, 1,
							0, 1, 1, 4096, 0, 0,
							0,
							3},//Layer-6 fc
							{1,
							1, 1, 4096, 1, 1, 4096, 4096, 4096,
							3,
							1, 1, 4096, 1, 0, 0, 1,
							0, 1, 1, 4096, 0, 0,
							0,
							2},//Layer-7 fc
							{1,
							1, 1, 4096, 1, 1, 4096, 1024, 1024,
							2,
							1, 1, 1024, 1, 0, 0, 0,
							0, 1, 1, 1024, 0, 0,
							0,
							3}//Layer-8 fc
							};
							
char precision_config[][3] ={{11, -1,  0},//Layer-6
							{10,  0,  2},//Layer-7
							{10,  2,  2}//Layer-8
							};
							
unsigned input_config[3] = {6, 6, 256}; //original image size

unsigned output_config[3] = {1, 1, 1024};//Layer-8
*/


/*
// Test Conv(Relu) without PooL and LRN and batch=1
// Alexnet Configuration
unsigned layer_config[][NUM_CONFIG_ITEM] = {{0,
							227, 227, 3, 11, 11, 3, 96, 96,
							0,
							55, 55, 96, 4, 0, 0, 0, // turn relu on if needed
							0, 55, 55, 96, 3, 2, // Note: memWR share the same params with pool, these params need also to be changed
							0,
							1}//Layer-1
							};

unsigned input_config[5] = {227, 227, 3, 1}; //original image size(dim1, dim2, dim3), batch size

unsigned output_config[3] = {55, 55, 96};//Layer-1

char precision_config[][3] ={{8, 0, -4}//Layer-1
							};
*/


/*
// Test Layer-1 batch=1
// Alexnet Configuration
unsigned layer_config[][NUM_CONFIG_ITEM] = {{0,
							227, 227, 3, 11, 11, 3, 96, 96,
							0,
							55, 55, 96, 4, 0, 0, 1,
							1, 27, 27, 96, 3, 2, // Note: memWR share the same params with pool, these params need also to be changed
							1,
							1}//Layer-1
							};

unsigned input_config[5] = {227, 227, 3, 1}; //original image size(dim1, dim2, dim3), batch size

unsigned output_config[3] = {27, 27, 96};//Layer-1

char precision_config[][3] ={{8, 0, -4}//Layer-1
							};
*/

/*
// Test Layer-1 batch=1
// VGG-16 Configuration
unsigned layer_config[][NUM_CONFIG_ITEM] = {{0,
							224, 224, 3, 3, 3, 3, 64, 64,
							0,
							224, 224, 64, 1, 1, 0, 1,
							0, 224, 224, 64, 0, 0,
							0,
							1}//Layer-1 (conv1_1)
							};

unsigned input_config[4] = {224, 224, 3, 1};

unsigned output_config[3] = {224, 224, 64};//Layer-1

char precision_config[][3] ={{7,  0, -2}//Layer-1
							};
*/

#ifdef ALEXNET
// Test with batch=1
// Alexnet Configuration
unsigned layer_config[][NUM_CONFIG_ITEM] = {{0,
							227, 227, 3, 11, 11, 3, 96, 96,
							0,
							55, 55, 96, 4, 0, 0, 1,
							1, 27, 27, 96, 3, 2,
							1,
							1},//Layer-1
							{0,
							27, 27, 96, 5, 5, 48, 256, 256,
							0,
							27, 27, 256, 1, 2, 1, 1,
							1, 13, 13, 256, 3, 2,
							1,
							1},//Layer-2
							{0,
							13, 13, 256, 3, 3, 256, 384, 384,
							0,
							13, 13, 384, 1, 1, 0, 1,
							0, 13, 13, 384, 0, 0,
							0,
							1},//Layer-3
							{0,
							13, 13, 384, 3, 3, 192, 384, 384,
							1,
							13, 13, 384, 1, 1, 1, 1,
							0, 13, 13, 384, 0, 0,
							0,
							0},//Layer-4
							{0,
							13, 13, 384, 3, 3, 192, 256, 256,
							0,
							13, 13, 256, 1, 1, 1, 1,
							1, 6, 6, 256, 3, 2,
							0,
							1},//Layer-5  Note: for last conv layer, outputs are write to fc buffer
							{1,
							6, 6, 256, 6, 6, 256, 4096, 4096,  // Note: The input size (dim1/dim2) is the combined data size (batched)
							4,
							1, 1, 4096, 6, 0, 0, 1,
							0, 1, 1, 4096, 0, 0,
							0,
							2},//Layer-6 fc
							{1,
							1, 1, 4096, 1, 1, 4096, 4096, 4096,
							2,
							1, 1, 4096, 1, 0, 0, 1,
							0, 1, 1, 4096, 0, 0,
							0,
							3},//Layer-7 fc
							{1,
							1, 1, 4096, 1, 1, 4096, 1024, 1024,
							3,
							1, 1, 1024, 1, 0, 0, 0,
							0, 1, 1, 1024, 0, 0,
							0,
							2}//Layer-8 fc
							};

char precision_config[][3] ={{8,  0, -4},//Layer-1
							{ 8,  0, -2},//Layer-2
							{ 8,  0, -1},//Layer-3
							{ 8, -1, -1},//Layer-4
							{ 8, -1, -1},//Layer-5
							{11, -1,  0},//Layer-6
							{10,  0,  2},//Layer-7
							{10,  2,  2}//Layer-8
							};

unsigned input_config[5] = {227, 227, 3, 1}; //original image size(dim1, dim2, dim3), batch size

// unsigned output_config[3] = {27, 27, 96};//Layer-1
//unsigned output_config[3] = {55, 55, 96};//Layer-1

// unsigned output_config[3] = {13, 13, 256};//Layer-2

// unsigned output_config[3] = {6, 6, 256};//Layer-5

// unsigned output_config[3] = {1, 1, 4096};//Layer-6

unsigned output_config[3] = {1, 1, 1024};//Layer-8  Note: only one result is extracted and verified
#endif

#ifdef VGG16
// Test with batch=1
// VGG-16 Configuration
unsigned layer_config[][NUM_CONFIG_ITEM] = {{0,
							224, 224, 3, 3, 3, 3, 64, 64,
							0,
							224, 224, 64, 1, 1, 0, 1,
							0, 224, 224, 64, 0, 0,
							0,
							1},//Layer-1 (conv1_1)
							{0,
							224, 224, 64, 3, 3, 64, 64, 64,
							1,
							224, 224, 64, 1, 1, 0, 1,
							1, 112, 112, 64, 2, 2,
							0,
							0},//Layer-2 (conv1_2)
							{0,
							112, 112, 64, 3, 3, 64, 128, 128,
							4,
							112, 112, 128, 1, 1, 0, 1,
							0, 112, 112, 128, 0, 0,
							0,
							1},//Layer-3 (conv2_1)
							{0,
							112, 112, 128, 3, 3, 128, 128, 128,
							1,
							112, 112, 128, 1, 1, 0, 1,
							1, 56, 56, 128, 2, 2,
							0,
							0},//Layer-4 (conv2_2)
							{0,
							56, 56, 128, 3, 3, 128, 256, 256,
							4,
							56, 56, 256, 1, 1, 0, 1,
							0, 56, 56, 256, 0, 0,
							0,
							1},//Layer-5 (conv3_1)
							{0,
							56, 56, 256, 3, 3, 256, 256, 256,
							1,
							56, 56, 256, 1, 1, 0, 1,
							0, 56, 56, 256, 0, 0,
							0,
							0},//Layer-6 (conv3_2)
							{0,
							56, 56, 256, 3, 3, 256, 256, 256,
							0,
							56, 56, 256, 1, 1, 0, 1,
							1, 28, 28, 256, 2, 2,
							0,
							1},//Layer-7 (conv3_3)
							{0,
							28, 28, 256, 3, 3, 256, 512, 512,
							4,
							28, 28, 512, 1, 1, 0, 1,
							0, 28, 28, 512, 0, 0,
							0,
							0},//Layer-8  (conv4_1)
							{0,
							28, 28, 512, 3, 3, 512, 512, 512,
							0,
							28, 28, 512, 1, 1, 0, 1,
							0, 28, 28, 512, 0, 0,
							0,
							1},//Layer-9  (conv4_2)
							{0,
							28, 28, 512, 3, 3, 512, 512, 512,
							1,
							28, 28, 512, 1, 1, 0, 1,
							1, 14, 14, 512, 2, 2,
							0,
							0},//Layer-10 (conv4_3)
							{0,
							14, 14, 512, 3, 3, 512, 512, 512,
							4,
							14, 14, 512, 1, 1, 0, 1,
							0, 14, 14, 512, 0, 0,
							0,
							1},//Layer-11  (conv5_1)
							{0,
							14, 14, 512, 3, 3, 512, 512, 512,
							1,
							14, 14, 512, 1, 1, 0, 1,
							0, 14, 14, 512, 0, 0,
							0,
							0},//Layer-12  (conv5_2)
							{0,
							14, 14, 512, 3, 3, 512, 512, 512,
							0,
							14, 14, 512, 1, 1, 0, 1,
							1, 7, 7, 512, 2, 2,
							0,
							1},//Layer-13  (conv5_3)    Note: for last conv layer, outputs are write to fc buffer
							{1,
							7, 7, 512, 7, 7, 512, 4096, 4096,
							4,
							1, 1, 4096, 7, 0, 0, 1,
							0, 1, 1, 4096, 0, 0,
							0,
							2},//Layer-14  (fc6)
							{1,
							1, 1, 4096, 1, 1, 4096, 4096, 4096,
							2,
							1, 1, 4096, 1, 0, 0, 1,
							0, 1, 1, 4096, 0, 0,
							0,
							3},//Layer-15  (fc7)
							{1,
							1, 1, 4096, 1, 1, 4096, 1024, 1024,
							3,
							1, 1, 1024, 1, 0, 0, 0,
							0, 1, 1, 1024, 0, 0,
							0,
							2}//Layer-16  (fc8)
							};

char precision_config[][3] ={{(char)7, (char) 0, (char)-2},//Layer-1
							{ (char)8, (char)-2, (char)-5},//Layer-2
							{ (char)8, (char)-5, (char)-5},//Layer-3
							{ (char)8, (char)-5, (char)-6},//Layer-4
							{ (char)7, (char)-6, (char)-7},//Layer-5
							{ (char)8, (char)-7, (char)-7},//Layer-6
							{ (char)8, (char)-7, (char)-7},//Layer-7
							{ (char)8, (char)-7, (char)-6},//Layer-8
							{ (char)8, (char)-6, (char)-5},//Layer-9
							{ (char)8, (char)-5, (char)-5},//Layer-10
							{ (char)9, (char)-5, (char)-4},//Layer-11
							{ (char)9, (char)-4, (char)-3},//Layer-12
							{ (char)8, (char)-3, (char)-2},//Layer-13
							{ (char)8, (char)-2, (char) 0},//Layer-14
							{ (char)7, (char) 0, (char) 2},//Layer-15
							{ (char)7, (char) 2, (char) 2}//Layer-16
							};

unsigned input_config[4] = {224, 224, 3, 1};

//unsigned output_config[3] = {224, 224, 64};//Layer-1

//unsigned output_config[3] = {56, 56, 128};//Layer-4(pool2)

//unsigned output_config[3] = {28, 28, 256};//Layer-7(pool3)

//unsigned output_config[3] = {28, 28, 512};//Layer-8(relu4_1)

//unsigned output_config[3] = {28, 28, 512};//Layer-9(relu4_2)

//unsigned output_config[3] = {14, 14, 512};//Layer-10(pool4)

//unsigned output_config[3] = {7, 7, 512};//Layer-13(pool5)

//unsigned output_config[3] = {1, 1, 4096};//Layer-14

unsigned output_config[3] = {1, 1, 1024};//Layer-16
#endif

#ifdef RESNET
// Test with batchsize=1
// ResNet Configuration
unsigned layer_config[][NUM_CONFIG_ITEM] = {
								{0,
								224,224,3,7,7,3,64,64,
								0,
								112,112,64,2,3,0,1,
								1,56,56,64,3,2,//maxpool
								0,
								1
								},//cov-1
								{0,
								56,56,64,1,1,64,256,256,
								4,
								56,56,256,1,0,0,0,
								0,0,0,0,0,0,
								0,
								5
								},//cov-2
								
								{0,
								56,56,64,1,1,64,64,64,
								4,
								56,56,64,1,0,0,1,
								0,0,0,0,0,0,
								0,
								0
								},//cov-3
								{0,
								56,56,64,3,3,64,64,64,
								0,
								56,56,64,1,1,0,1,
								0,0,0,0,0,0,
								0,
								1
								},//cov-5
								{0,
								56,56,64,1,1,64,256,256,
								1,
								56,56,256,1,0,0,0,
								0,0,0,0,0,0,
								0,
								0
								},//cov-5
								{0,
								56,56,256,1,1,256,64,64,
								1,
								56,56,64,1,0,0,1,
								0,0,0,0,0,0,
								0,
								0
								},//cov-6
								{0,
								56,56,64,3,3,64,64,64,
								0,
								56,56,64,1,1,0,1,
								0,0,0,0,0,0,
								0,
								5
								},//cov-7
								{0,
								56,56,64,1,1,64,256,256,
								5,
								56,56,256,1,0,0,0,
								0,0,0,0,0,0,
								0,
								0
								},//cov-8
								{0,
								56,56,256,1,1,256,64,64,
								5,
								56,56,64,1,0,0,1,
								0,0,0,0,0,0,
								0,
								1
								},//cov-9
								{0,
								56,56,64,3,3,64,64,64,
								1,
								56,56,64,1,1,0,1,
								0,0,0,0,0,0,
								0,
								0
								},//cov-10
								{0,
								56,56,64,1,1,64,256,256,
								0,
								56,56,256,1,0,0,0,
								2,28,28,256,2,2,
								0,
								1
								},//cov-11
								{0,
								28,28,256,1,1,256,512,512,
								0,
								28,28,512,1,0,0,0,
								0,0,0,0,0,0,
								0,
								5
								},//cov-12
								{0,
								28,28,256,1,1,256,128,128,
								0,
								28,28,128,1,0,0,1,
								0,0,0,0,0,0,
								0,
								1
								},//cov-13
								{0,
								28,28,128,3,3,128,128,128,
								1,
								28,28,128,1,1,0,1,
								0,0,0,0,0,0,
								0,
								0
								},//cov-14
								{0,
								28,28,128,1,1,128,512,512,
								0,
								28,28,512,1,0,0,0,
								0,0,0,0,0,0,
								0,
								1
								},//cov-15
								{0,
								28,28,512,1,1,512,128,128,
								0,
								28,28,128,1,0,0,1,
								0,0,0,0,0,0,
								0,
								1
								},//cov-16
								{0,
								28,28,128,3,3,128,128,128,
								1,
								28,28,128,1,1,0,1,
								0,0,0,0,0,0,
								0,
								5
								},//cov-17
								{0,
								28,28,128,1,1,128,512,512,
								5,
								28,28,512,1,0,0,0,
								0,0,0,0,0,0,
								0,
								1
								},//cov-18
								{0,
								28,28,512,1,1,512,128,128,
								5,
								28,28,128,1,0,0,1,
								0,0,0,0,0,0,
								0,
								0
								},//cov-19
								{0,
								28,28,128,3,3,128,128,128,
								0,
								28,28,128,1,1,0,1,
								0,0,0,0,0,0,
								0,
								1
								},//cov-20
								{0,
								28,28,128,1,1,128,512,512,
								1,
								28,28,512,1,0,0,0,
								0,0,0,0,0,0,
								0,
								0
								},//cov-21
								{0,
								28,28,512,1,1,512,128,128,
								1,
								28,28,128,1,0,0,1,
								0,0,0,0,0,0,
								0,
								0
								},//cov-22
								{0,
								28,28,128,3,3,128,128,128,
								0,
								28,28,128,1,1,0,1,
								0,0,0,0,0,0,
								0,
								5
								},//cov-23
								{0,
								28,28,128,1,1,128,512,512,
								5,
								28,28,512,1,0,0,0,
								2,14,14,512,2,2,
								0,
								0
								},//cov-24
								{0,
								14,14,512,1,1,512,1024,1024,
								5,
								14,14,1024,1,0,0,0,
								0,0,0,0,0,0,
								0,
								1
								},//cov-25
								{0,
								14,14,512,1,1,512,256,256,
								5,
								14,14,256,1,0,0,1,
								0,0,0,0,0,0,
								0,
								0
								},//cov-26

								{0,
								14,14,256,3,3,256,256,256,
								0,
								14,14,256,1,1,0,1,
								0,0,0,0,0,0,
								0,
								5
								},//cov-27
								{0,
								14,14,256,1,1,256,1024,1024,
								5,
								14,14,1024,1,0,0,0,
								0,0,0,0,0,0,
								0,
								0
								},//cov-28
								{0,
								14,14,1024,1,1,1024,256,256,
								5,
								14,14,256,1,0,0,1,
								0,0,0,0,0,0,
								0,
								0
								},//cov-29
								{0,
								14,14,256,3,3,256,256,256,
								0,
								14,14,256,1,1,0,1,
								0,0,0,0,0,0,
								0,
								1
								},//cov-30
								{0,
								14,14,256,1,1,256,1024,1024,
								1,
								14,14,1024,1,0,0,0,
								0,0,0,0,0,0,
								0,
								0
								},//cov-31
								{0,
								14,14,1024,1,1,1024,256,256,
								1,
								14,14,256,1,0,0,1,
								0,0,0,0,0,0,
								0,
								0
								},//cov-32
								{0,
								14,14,256,3,3,256,256,256,
								0,
								14,14,256,1,1,0,1,
								0,0,0,0,0,0,
								0,
								5
								},//cov-33
								{0,
								14,14,256,1,1,256,1024,1024,
								5,
								14,14,1024,1,0,0,0,
								0,0,0,0,0,0,
								0,
								0
								},//cov-34
								{0,
								14,14,1024,1,1,1024,256,256,
								5,
								14,14,256,1,0,0,1,
								0,0,0,0,0,0,
								0,
								1
								},//cov-35
								{0,
								14,14,256,3,3,256,256,256,
								1,
								14,14,256,1,1,0,1,
								0,0,0,0,0,0,
								0,
								0
								},//cov-36
								{0,
								14,14,256,1,1,256,1024,1024,
								0,
								14,14,1024,1,0,0,0,
								0,0,0,0,0,0,
								0,
								1
								},//cov-37
								{0,
								14,14,1024,1,1,1024,256,256,
								0,
								14,14,256,1,0,0,1,
								0,0,0,0,0,0,
								0,
								1
								},//cov-38
								{0,
								14,14,256,3,3,256,256,256,
								1,
								14,14,256,1,1,0,1,
								0,0,0,0,0,0,
								0,
								5
								},//cov-39
								{0,
								14,14,256,1,1,256,1024,1024,
								5,
								14,14,1024,1,0,0,0,
								0,0,0,0,0,0,
								0,
								1
								},//cov-40
								{0,
								14,14,1024,1,1,1024,256,256,
								5,
								14,14,256,1,0,0,1,
								0,0,0,0,0,0,
								0,
								0
								},//cov-41
								{0,
								14,14,256,3,3,256,256,256,
								0,
								14,14,256,1,1,0,1,
								0,0,0,0,0,0,
								0,
								1
								},//cov-42
								{0,
								14,14,256,1,1,256,1024,1024,
								1,
								14,14,1024,1,0,0,0,
								2,7,7,1024,2,2,
								0,
								0
								},//cov-43
								{0,
								7,7,1024,1,1,1024,2048,2048,
								1,
								7,7,2048,1,0,0,0,
								0,0,0,0,0,0,
								0,
								5
								},//cov-44
								{0,
								7,7,1024,1,1,1024,512,512,
								1,
								7,7,512,1,0,0,1,
								0,0,0,0,0,0,
								0,
								0
								},//cov-45
								{0,
								7,7,512,3,3,512,512,512,
								0,
								7,7,512,1,1,0,1,
								0,0,0,0,0,0,
								0,
								1
								},//cov-46
								{0,
								7,7,512,1,1,512,2048,2048,
								1,
								7,7,2048,1,0,0,0,
								0,0,0,0,0,0,
								0,
								0
								},//cov-47
								{0,
								7,7,2048,1,1,2048,512,512,
								1,
								7,7,512,1,0,0,1,
								0,0,0,0,0,0,
								0,
								0
								},//cov-48
								{0,
								7,7,512,3,3,512,512,512,
								0,
								7,7,512,1,1,0,1,
								0,0,0,0,0,0,
								0,
								5
								},//cov-49
								{0,
								7,7,512,1,1,512,2048,2048,
								5,
								7,7,2048,1,0,0,0,
								0,0,0,0,0,0,
								0,
								0
								},//cov-50
								{0,
								7,7,2048,1,1,2048,512,512,
								5,
								7,7,512,1,0,0,1,
								0,0,0,0,0,0,
								0,
								1
								},//cov-51
								{0,
								7,7,512,3,3,512,512,512,
								1,
								7,7,512,1,1,0,1,
								0,0,0,0,0,0,
								0,
								0
								},//cov-52
								{0,
								7,7,512,1,1,512,2048,2048,
								0,
								7,7,2048,1,0,0,0,
								3,1,1,2048,7,1,//for last conv after eltwise is avgpool
								0,
								1
								},//cov-53
								{1,
								1,1,2048,1,1,2048,1024,1024,
								2,
								1,1,1024,1,0,0,0,
								0,0,0,0,0,0,
								0,
								3,
								}//fc
};

unsigned input_config[4] = {224, 224, 3, 1}; //original image size(dim1, dim2, dim3), batch size
unsigned output_config[3] = {1,1,1024};//Note: only one result is extracted and verified
// unsigned output_config[3] = {112,112,64};//conv1_sc
// unsigned output_config[3] = {56,56,64};//conv1_pool
// unsigned output_config[3] = {56,56,256};//conv11_sc
// unsigned output_config[3] = {28,28,256};//conv11_pool
// unsigned output_config[3] = {28,28,512};//conv12_sc
// unsigned output_config[3] = {28,28,128}
// unsigned output_config[3] = {14,14,256};
// unsigned output_config[3] = {14,14,1024};
// unsigned output_config[3] = {7,7,2048};//conv50_relu
// unsigned output_config[3] = {7,7,512};//conv52_relu
// unsigned output_config[3] = {1,1,2048};//conv53_pool

//which conv layer follow eltwise layer
unsigned eltwise_config[][4]={
								{0,0,0,0},//layer-1
								{0,0,0,0},//layer-2
								{0,0,0,0},//layer-3
								{0,0,0,0},//layer-5
								{1,5,0,1},//layer-5
								{0,0,0,0},//layer-6
								{0,0,0,0},//layer-7
								{1,1,0,5},//layer-8
								{0,0,0,0},//layer-9
								{0,0,0,0},//layer-10
								{1,5,1,0},//layer-11
								{0,0,0,0},//layer-12
								{0,0,0,0},//layer-13
								{0,0,0,0},//layer-14
								{1,5,1,0},//layer-15
								{0,0,0,0},//layer-16
								{0,0,0,0},//layer-17
								{1,0,1,5},//layer-18
								{0,0,0,0},//layer-19
								{0,0,0,0},//layer-20
								{1,5,0,1},//layer-21
								{0,0,0,0},//layer-22
								{0,0,0,0},//layer-23
								{1,1,0,5},//layer-24
								{0,0,0,0},//layer-25
								{0,0,0,0},//layer-26
								{0,0,0,0},//layer-27
								{1,1,0,5},//layer-28
								{0,0,0,0},//layer-29
								{0,0,0,0},//layer-30
								{1,5,0,1},//layer-31
								{0,0,0,0},//layer-32
								{0,0,0,0},//layer-33
								{1,1,0,5},//layer-34
								{0,0,0,0},//layer-35
								{0,0,0,0},//layer-36
								{1,5,1,0},//layer-37
								{0,0,0,0},//layer-38
								{0,0,0,0},//layer-39
								{1,0,1,5},//layer-40
								{0,0,0,0},//layer-41
								{0,0,0,0},//layer-42
								{1,5,0,1},//layer-43
								{0,0,0,0},//layer-44
								{0,0,0,0},//layer-45
								{0,0,0,0},//layer-46
								{1,5,0,1},//layer-47
								{0,0,0,0},//layer-48
								{0,0,0,0},//layer-49
								{1,1,0,5},//layer-50
								{0,0,0,0},//layer-51
								{0,0,0,0},//layer-52
								{1,5,1,2},//layer-53,for last cov out to fc_1_buf
								{0,0,0,0} //layer-54
								};

//save the layer's previous layer						
unsigned eltwise_layer_previous[]={0,1,1,3,4,5,6,7,8,9,
								   10,11,11,13,14,15,16,17,18,19,
								   20,21,22,23,24,24,26,27,28,29,
								   30,31,32,33,34,35,36,37,38,39,
								   40,41,42,43,43,45,46,47,48,49,
								   50,51,52,53};


//frac_w, frac_din, frac_dout
// ((frac_w+frac_din)-frac_dout))>0
// if have bias (frac_w-frac_dout-1)>0
char precision_config[][3] ={										
{	7	,	0	,	-4	}	,	//	layer-1	
{	7	,	3	,	2	}	,	//	layer-2	
{	7	,	3	,	2	}	,	//	layer-3	
{	8	,	4	,	4	}	,	//	layer-4	
{	8	,	3	,	3	}	,	//	layer-5	
{	8	,	3	,	4	}	,	//	layer-6	
{	8	,	3	,	4	}	,	//	layer-7	
{	8	,	1	,	6	}	,	//	layer-8	
{	8	,	3	,	2	}	,	//	layer-9	
{	9	,	4	,	5	}	,	//	layer-10	
{	8	,	1	,	5	}	,	//	layer-11	
{	7	,	4	,	3	}	,	//	layer-12	
{	8	,	4	,	4	}	,	//	layer-13	
{	8	,	5	,	4	}	,	//	layer-14	
{	8	,	4	,	6	}	,	//	layer-15	
{	9	,	3	,	5	}	,	//	layer-16	
{	9	,	4	,	5	}	,	//	layer-17	
{	8	,	4	,	5	}	,	//	layer-18	
{	8	,	4	,	2	}	,	//	layer-19	
{	8	,	4	,	4	}	,	//	layer-20	
{	8	,	4	,	4	}	,	//	layer-21	
{	8	,	2	,	1	}	,	//	layer-22	
{	8	,	2	,	5	}	,	//	layer-23	
{	8	,	4	,	5	}	,	//	layer-24	
{	8	,	2	,	4	}	,	//	layer-25	
{	8	,	2	,	0	}	,	//	layer-26	
{	8	,	5	,	1	}	,	//	layer-27	
{	8	,	4	,	6	}	,	//	layer-28	
{	9	,	3	,	2	}	,	//	layer-29	
{	8	,	4	,	4	}	,	//	layer-30	
{	8	,	5	,	6	}	,	//	layer-31	
{	8	,	2	,	4	}	,	//	layer-32	
{	8	,	3	,	5	}	,	//	layer-33	
{	8	,	3	,	8	}	,	//	layer-34	
{	8	,	2	,	4	}	,	//	layer-35	
{	9	,	4	,	5	}	,	//	layer-36	
{	9	,	4	,	7	}	,	//	layer-37	
{	8	,	2	,	4	}	,	//	layer-38	
{	9	,	4	,	6	}	,	//	layer-39	
{	8	,	3	,	4	}	,	//	layer-40	
{	8	,	2	,	3	}	,	//	layer-41	
{	8	,	2	,	5	}	,	//	layer-42	
{	8	,	3	,	7	}	,	//	layer-43	
{	7	,	2	,	5	}	,	//	layer-44	
{	8	,	2	,	3	}	,	//	layer-45	
{	8	,	5	,	3	}	,	//	layer-46	
{	8	,	3	,	6	}	,	//	layer-47	
{	7	,	2	,	3	}	,	//	layer-48	
{	8	,	2	,	6	}	,	//	layer-49	
{	8	,	5	,	5	}	,	//	layer-50	
{	7	,	1	,	3	}	,	//	layer-51	
{	9	,	3	,	3	}	,	//	layer-52	
{	8	,	3	,	5	}	,	//	layer-53	
{	7	,	4	,	2	}		//	layer-54	
};										
									
								
								
char addition_precision_config[][4]={											
{	3	,	0	,	0	,	0	}	,	//	layer-1
{	3	,	0	,	0	,	0	}	,	//	layer-2
{	4	,	0	,	0	,	0	}	,	//	layer-3
{	3	,	0	,	0	,	0	}	,	//	layer-4
{	4	,	3	,	4	,	3	}	,	//	layer-5
{	3	,	0	,	0	,	0	}	,	//	layer-6
{	1	,	0	,	0	,	0	}	,	//	layer-7
{	2	,	3	,	2	,	3	}	,	//	layer-8
{	4	,	0	,	0	,	0	}	,	//	layer-9
{	1	,	0	,	0	,	0	}	,	//	layer-10
{	2	,	3	,	2	,	4	}	,	//	layer-11
{	3	,	0	,	0	,	0	}	,	//	layer-12
{	5	,	0	,	0	,	0	}	,	//	layer-13
{	4	,	0	,	0	,	0	}	,	//	layer-14
{	3	,	3	,	3	,	3	}	,	//	layer-15
{	4	,	0	,	0	,	0	}	,	//	layer-16
{	4	,	0	,	0	,	0	}	,	//	layer-17
{	4	,	3	,	4	,	4	}	,	//	layer-18
{	4	,	0	,	0	,	0	}	,	//	layer-19
{	4	,	0	,	0	,	0	}	,	//	layer-20
{	3	,	4	,	3	,	2	}	,	//	layer-21
{	2	,	0	,	0	,	0	}	,	//	layer-22
{	4	,	0	,	0	,	0	}	,	//	layer-23
{	2	,	2	,	2	,	2	}	,	//	layer-24
{	3	,	0	,	0	,	0	}	,	//	layer-25
{	5	,	0	,	0	,	0	}	,	//	layer-26
{	4	,	0	,	0	,	0	}	,	//	layer-27
{	3	,	3	,	3	,	3	}	,	//	layer-28
{	4	,	0	,	0	,	0	}	,	//	layer-29
{	5	,	0	,	0	,	0	}	,	//	layer-30
{	4	,	3	,	4	,	2	}	,	//	layer-31
{	3	,	0	,	0	,	0	}	,	//	layer-32
{	3	,	0	,	0	,	0	}	,	//	layer-33
{	4	,	2	,	4	,	2	}	,	//	layer-34
{	4	,	0	,	0	,	0	}	,	//	layer-35
{	4	,	0	,	0	,	0	}	,	//	layer-36
{	4	,	2	,	4	,	2	}	,	//	layer-37
{	4	,	0	,	0	,	0	}	,	//	layer-38
{	3	,	0	,	0	,	0	}	,	//	layer-39
{	2	,	2	,	2	,	2	}	,	//	layer-40
{	2	,	0	,	0	,	0	}	,	//	layer-41
{	3	,	0	,	0	,	0	}	,	//	layer-42
{	4	,	2	,	4	,	2	}	,	//	layer-43
{	2	,	0	,	0	,	0	}	,	//	layer-44
{	5	,	0	,	0	,	0	}	,	//	layer-45
{	3	,	0	,	0	,	0	}	,	//	layer-46
{	4	,	2	,	4	,	2	}	,	//	layer-47
{	2	,	0	,	0	,	0	}	,	//	layer-48
{	5	,	0	,	0	,	0	}	,	//	layer-49
{	3	,	2	,	3	,	1	}	,	//	layer-50
{	3	,	0	,	0	,	0	}	,	//	layer-51
{	3	,	0	,	0	,	0	}	,	//	layer-52
{	3	,	1	,	3	,	4	}	,	//	layer-53,elt_out for avgpool frac
{	0	,	0	,	0	,	0	}	,	//	layer-54
};											
											
#endif

