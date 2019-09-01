package ���Ա�˳��洢�ṹ;
/**
 * 	������Ա�����������ͽӿ�
 * 
 **/

public class SequenceList implements List{
	//����	
	final int defaultSize = 10;	//Ĭ��˳������󳤶�	
	int maxSize;				//��󳤶�	
	int size;					//��ǰ����
	Object[] listArray;			//��������
	
	//����	
	//������
	public SequenceList() {
		init(defaultSize);
	}
	public SequenceList(int size) {
		init(size);
	}
	
	//˳���ĳ�ʼ������
	private void init(int size) {
		maxSize = size;
		this.size = 0;
		listArray = new Object[size];
	}
	
	@Override
	public int size() {
		
		return size;
	}
	@Override
	public boolean isEmpty() {
		
		return size==0;
	}
	@Override
	public void insert(int index, Object obj) throws Exception {
		//���Ա����� �ǾͲ������������
		if(size == maxSize) {
			throw new Exception("˳����������޷����룡");
		}
		//����λ�ñ���Ƿ�Ϸ�
		if(index<0||index >size) {
			throw new Exception("��������");
		}
		for(int i=size-1;i>=index;i--) {
			listArray[i+1]=listArray[i];
		}
		listArray[index]=obj;
		size++;
	}
	@Override
	public void delete(int index) throws Exception {
		if(isEmpty()) {
			throw new Exception("˳���Ϊ�գ��޷�ɾ����");
		}
		if(index<0||index>size-1) {
			throw new Exception("��������");
		}
		for(int i=index;i<size-1;i++) {
			listArray[i]=listArray[i+1];//�ƶ�Ԫ��
		}			
		size--;
	}
	@Override
	public Object get(int index) throws Exception {
		if (index < 0 || index > size-1) {
		     throw new Exception("��������");
		 }
		 return listArray[index];
	}
	
	

}
