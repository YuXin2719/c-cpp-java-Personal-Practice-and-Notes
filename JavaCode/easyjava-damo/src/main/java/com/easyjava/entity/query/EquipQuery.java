package com.easyjava.entity.query;



/**
 * @description:查询对象
 * @Author:YuXin
 * @date:2025/02/26
 */
public class EquipQuery {
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
	private Integer playerId;

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

	public void setPlayerId(Integer playerId) {
		this.playerId = playerId;
	}

	public Integer getPlayerId() {
		return this.playerId;
	}

	public void setNameFuzzy(String nameFuzzy) {
		this.nameFuzzy = nameFuzzy;
	}

	public String getNameFuzzy() {
		return this.nameFuzzy;
	}

}