package com.easyjava.entity.query;



/**
 * @description:查询对象
 * @Author:YuXin
 * @date:2025/02/26
 */
public class NewPlayerQuery {
	/**
	 * 
	 */
	private Integer id;

	/**
	 * 
	 */
	private String name;

	private String nameFuzzy;

	/**
	 * 
	 */
	private Integer level;

	public void setId(Integer id) {
		this.id = id;
	}

	public Integer getId() {
		return this.id;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getName() {
		return this.name;
	}

	public void setLevel(Integer level) {
		this.level = level;
	}

	public Integer getLevel() {
		return this.level;
	}

	public void setNameFuzzy(String nameFuzzy) {
		this.nameFuzzy = nameFuzzy;
	}

	public String getNameFuzzy() {
		return this.nameFuzzy;
	}

}