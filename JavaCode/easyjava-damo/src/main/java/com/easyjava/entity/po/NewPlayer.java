package com.easyjava.entity.po;

import java.io.Serializable;


/**
 * @description:
 * @Author:YuXin
 * @date:2025/02/26
 */
public class NewPlayer implements Serializable {
	/**
	 * 
	 */
	private Integer id;

	/**
	 * 
	 */
	private String name;

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

	@Override
	public String toString() {
		return ":" + (id == null ? "空" : id) + ",:" + (name == null ? "空" : name) + ",:" + (level == null ? "空" : level);
	}
}