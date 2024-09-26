///*Figure 4.6 Routine to list a directory in a hierarchial等级制度的 file system */
//static void ListDir(DirectoryOrFile D, int Depth){
//	if(D is a legitimate entry){
//		PrintName(D,Depth);
//		if(D is a directory){
//			for each child C , of D
//				ListDir(C,Depth++);
//		}
//	}
//}
//void ListDirectory(DirectoryOrFile D){
//	ListDir(D,0);
//}

///*Figure 4.9 Routine to calculate the size of a directory
//to calculate the total number of blocks used by all the files in the tree.*/
//static void SizeDirectory(DirectoryOrFile D){
//	int TotalSize=0;
//	if(D is a legitimate entry){
//		TotalSize=FileSize(D);
//		if(D is a directory) {
//			for each chile,C of D
//				TotalSize+=SizeDirectory(C);
//		}
//	}
//	return TotalSize;
//}
