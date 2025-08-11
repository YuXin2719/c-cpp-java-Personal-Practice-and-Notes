package com.easyjava.entity.query;



/**
 * @description:部门查询对象
 * @Author:YuXin
 * @date:2025/02/26
 */
public class ItemQuery {
	/**
	 * ID
	 */
	private Long id;

	/**
	 * 名称
	 */
	private String name;

	private String nameFuzzy;

	/**
	 * 描述
	 */
	private String description;

	private String descriptionFuzzy;

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

	public void setNameFuzzy(String nameFuzzy) {
		this.nameFuzzy = nameFuzzy;
	}

	public String getNameFuzzy() {
		return this.nameFuzzy;
	}

	public void setDescriptionFuzzy(String descriptionFuzzy) {
		this.descriptionFuzzy = descriptionFuzzy;
	}

	public String getDescriptionFuzzy() {
		return this.descriptionFuzzy;
	}

}