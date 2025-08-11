package com.easyjava.entity.po;

import java.io.Serializable;


/**
 * @description:部门
 * @Author:YuXin
 * @date:2025/02/26
 */
public class Item implements Serializable {
	/**
	 * ID
	 */
	private Long id;

	/**
	 * 名称
	 */
	private String name;

	/**
	 * 描述
	 */
	private String description;

	public void setId(Long id) {
		this.id = id;
	}

	public Long getId() {
		return this.id;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getName() {
		return this.name;
	}

	public void setDescription(String description) {
		this.description = description;
	}

	public String getDescription() {
		return this.description;
	}

	@Override
	public String toString() {
		return "ID:" + (id == null ? "空" : id) + ",名称:" + (name == null ? "空" : name) + ",描述:" + (description == null ? "空" : description);
	}
}