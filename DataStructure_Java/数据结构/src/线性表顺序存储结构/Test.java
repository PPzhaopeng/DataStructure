package ���Ա�˳��洢�ṹ;

public class Test {
	public static void main(String[] args) {
//		SequenceList list = new SequenceList(20);
//		try {
//			list.insert(0, 100);
//			list.insert(0, 50);
//			list.insert(1, 20);
//			System.out.println(list.toString());
//			for(int i=0;i<list.size;i++){
//				System.out.println("��"+i+"��Ԫ��Ϊ��"+list.get(i));
//			}
//		}catch(Exception e) {
//			e.printStackTrace();
//		}
		
		SequenceList list = new SequenceList(100);
		try {
			list.insert(list.size, new Students("s0001","����","��",18));
			list.insert(list.size, new Students("s0002","����","��",19));
			list.insert(list.size, new Students("s0003","����","��",16));
			list.insert(list.size, new Students("s0004","����","��",17));
			for(int i=0;i<list.size;i++) {
				System.out.println(list.get(i));
			}
				
			
		}catch(Exception e) {
			e.printStackTrace();
		}	
	}
}
