package com.easyjava.entity.po;

import java.io.Serializable;
import java.math.BigDecimal;

/**
 * @description:
 * @Author:YuXin
 * @date:2025/02/26
 */
public class NewPlayer1 implements Serializable {
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
	private String sex;

	/**
	 * 
	 */
	private String email;

	/**
	 * 
	 */
	private Integer level;

	/**
	 * 
	 */
	private Integer exp;

	/**
	 * 
	 */
	private BigDecimal gold;

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

	public void setSex(String sex) {
		this.sex = sex;
	}

	public String getSex() {
		return this.sex;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getEmail() {
		return this.email;
	}

	public void setLevel(Integer level) {
		this.level = level;
	}

	public Integer getLevel() {
		return this.level;
	}

	public void setExp(Integer exp) {
		this.exp = exp;
	}

	public Integer getExp() {
		return this.exp;
	}

	public void setGold(BigDecimal gold) {
		this.gold = gold;
	}

	public BigDecimal getGold() {
		return this.gold;
	}

	@Override
	public String toString() {
		return ":" + (id == null ? "空" : id) + ",:" + (name == null ? "空" : name) + ",:" + (sex == null ? "空" : sex) + ",:" + (email == null ? "空" : email) + ",:" + (level == null ? "空" : level) + ",:" + (exp == null ? "空" : exp) + ",:" + (gold == null ? "空" : gold);
	}
}