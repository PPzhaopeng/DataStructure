package ���Ա�˳��洢�ṹ;

public interface List {
	//������Ա���
	public int size();
	//�ж����Ա��Ƿ�Ϊ��
	public boolean isEmpty();
	//����Ԫ�� �����Ա�ĵ�indexԪ��֮ǰ�����µ�Ԫ�� obj
	public void insert(int index,Object obj) throws Exception;
	//ɾ��Ԫ��
	public void delete(int index) throws Exception;
	//��ȡָ��λ�õ�Ԫ��
	public Object get(int index) throws Exception;
}
