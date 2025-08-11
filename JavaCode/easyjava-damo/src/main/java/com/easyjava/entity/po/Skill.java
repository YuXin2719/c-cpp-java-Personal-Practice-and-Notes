package com.easyjava.entity.po;

import java.io.Serializable;


/**
 * @description:
 * @Author:YuXin
 * @date:2025/02/26
 */
public class Skill implements Serializable {
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

	@Override
	public String toString() {
		return ":" + (id == null ? "空" : id) + ",:" + (name == null ? "空" : name) + ",:" + (playerId == null ? "空" : playerId);
	}
}