package ���Ա�˳��洢�ṹ;

public class Students {
	private String id;//ѧ��
	private String name;//����
	private String gender;//�Ա�
	private int age;//����
	
	public Students() {
		
	}
	public Students(String id,String name,String gender,int age) {
		this.id = id;
		this.name = name;
		this.gender = gender;
		this.age = age;
	}
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getGender() {
		return gender;
	}
	public void setGender(String gender) {
		this.gender = gender;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public String toString() {
		return "ѧ�ţ�"+this.getId()+"������"+this.getName()+"�Ա�"+
				this.getGender()+"����"+this.getAge();
	}
	
}
