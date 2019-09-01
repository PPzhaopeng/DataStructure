package 线性表顺序存储结构;
/**
 * 	设计线性表抽象数据类型接口
 * 
 **/

public class SequenceList implements List{
	//属性	
	final int defaultSize = 10;	//默认顺序表的最大长度	
	int maxSize;				//最大长度	
	int size;					//当前长度
	Object[] listArray;			//对象数组
	
	//方法	
	//构造器
	public SequenceList() {
		init(defaultSize);
	}
	public SequenceList(int size) {
		init(size);
	}
	
	//顺序表的初始化方法
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
		//线性表已满 那就不允许插入数据
		if(size == maxSize) {
			throw new Exception("顺序表已满，无法插入！");
		}
		//插入位置编号是否合法
		if(index<0||index >size) {
			throw new Exception("参数错误！");
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
			throw new Exception("顺序表为空，无法删除！");
		}
		if(index<0||index>size-1) {
			throw new Exception("参数错误！");
		}
		for(int i=index;i<size-1;i++) {
			listArray[i]=listArray[i+1];//移动元素
		}			
		size--;
	}
	@Override
	public Object get(int index) throws Exception {
		if (index < 0 || index > size-1) {
		     throw new Exception("参数错误！");
		 }
		 return listArray[index];
	}
	
	

}
